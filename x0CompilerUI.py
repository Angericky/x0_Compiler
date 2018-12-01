import sys, os, time
import json
import codecs
import threading
from PyQt5.QtWidgets import QWidget, QApplication, QMainWindow, QApplication, QAbstractItemView, \
		QFileDialog, QTableWidgetItem, QMessageBox
from PyQt5.QtGui import QPainter, QColor, QFont, QBrush, QSyntaxHighlighter, QTextCharFormat
from PyQt5.QtCore import Qt, QRegExp,  QFile
from PyQt5 import QtGui, QtCore, uic
from PyQt5.QtWidgets import qApp
from utils import Instruction, Interpret
import re

UI_MainWindow, QtBaseClass = uic.loadUiType("x0Compiler.ui")

qssFile = QFile("style.qss")
qssFile.open(QFile.ReadOnly)
themeQss = qssFile.readAll()
themeQss = str(themeQss, encoding="utf8")

'''
	delete temporary files after a build work finished
'''
def cleanfiles():
	from os.path import isfile
	if isfile(".\\~.tmp"):
		os.remove(".\\~.tmp")
	if isfile(os.getcwd()+"\\ferr.json"):
		os.remove(os.getcwd()+"\\ferr.json")
	if isfile(os.getcwd()+"\\fcode.json"):
		os.remove(os.getcwd()+"\\fcode.json")

'''
	This function is the real processing for backstage-interpretation
	and it should work in a new thread so that I/O cannot block the UI
'''
def procRun(codeList, window):
	window.interpret = Interpret(codeList)
	run = window.interpret
	mod = window.mod
	window.setStackValues(run.showStack())
	while True:
		# tip the current processing TAC code
		window.setCodeStatus(run.p, True)

		tag = run.sg_step()
		window.setStackValues(run.showStack())
		if tag == 1:	#input
			window.input()
		if tag == 2:	#output
			window.output(run.recv())

		if window.stopsgl == 1:
			window.setCodeStatus(run.c, False)
			break
		if run.judge() == False:
			break

		if mod == 1:
			while window.debug == 0:
				time.sleep(0.05)
			window.setCodeStatus(run.c, False)
			if window.debug == 1:	# next step
				pass
			if window.debug == 2:	# step into
				pass
			if window.debug == 3:	# over step
				mod = 0
				window.setDebugEnabled(False)
			if window.debug == 4:	# step out
				run.paramInit()
				window.RuntimePad.clear()
				window.RuntimePad.textCursor().insertText("")
				window.debug = 0
				continue
			window.debug = 0
		# cancel the tip for TAC code just processing
		window.setCodeStatus(run.c, False)
		
	window.setDebugEnabled(False)
	window.actionStop.setEnabled(False)
	window.output("\n=== the processing is over ===")


'''
	extending the QSyntaxHighlighter class for highlight the x0 texts
'''
class x0Highlighter(QSyntaxHighlighter):

	Rules = []
	Formats = {}

	def __init__(self, parent=None):
		super(x0Highlighter, self).__init__(parent)
		self.initializeFormats()

		BUILDINS = ["and",	"not",	"int", "char", "bool", "true", "false"]

		OPERATORS = ["\+", "-", "\*", "/", "%", "&", "\|", "~", "\^", "\!",
					 "<", ">", "=", "\.","+="]
		KEYWORDS = ["read",		"if",		"else",
					"for",		"do",		"while",	"repeat",	"until",
					"write",	"return",	"break",	"continue",
					"main",  	"switch", 	"case"]
		FUNCTIONS = ["procedure",	"call"]
		CONSTANTS = ["False", 	"True"]
		x0Highlighter.Rules.append((QRegExp(
			"|".join([r"\b%s\b" % keyword for keyword in KEYWORDS])),
			"keyword"))
		x0Highlighter.Rules.append((QRegExp(
			"|".join([r"\b%s\b" % buildin for buildin in BUILDINS])),
			"buildin"))
		x0Highlighter.Rules.append((QRegExp(
			"|".join([r"%s" % operator for operator in OPERATORS])),
			"operator"))
		x0Highlighter.Rules.append((QRegExp(
			"|".join([r"%s" % function for function in FUNCTIONS])),
			"function"))
		x0Highlighter.Rules.append((QRegExp(
			r"\b[+-]?[0-9]+[lL]?\b"),
			"number"))
		x0Highlighter.Rules.append((QRegExp(
			r"(/\*(.|\n)*\*/)|(\/\/.*/n)"),
			"comment"))
		x0Highlighter.Rules.append((QRegExp(
			r"\".*\"|'.*'"),
			"string"))
		x0Highlighter.Rules.append((QRegExp(
			r"procedure.*)\("),
			"funcName"))
		
	@staticmethod
	def initializeFormats():
		baseFormat = QTextCharFormat()
		baseFormat.setFontFamily("Consolas")
		baseFormat.setFontPointSize(12)
		for name, fcolor, bcolor in (
			("operator", QColor(103,166,228), None),
			("keyword", QColor(249,35,112), None),
			("buildin", QColor(104,216,235), None), 
			("normal", Qt.white, None),
			("string", QColor(231,219,116), None),
			("function", QColor(245,150,32), None),
			("funcName", QColor(166,226,44), None),
			("number", QColor(167,128,255), None),
			("comment", QColor(90,88,85), None)):
			format = QTextCharFormat(baseFormat)
			format.setForeground(QColor(fcolor))
			if bcolor is not None:
				format.setBackground(QColor(bcolor))
			if name in ("buildin"):
				format.setFontWeight(QFont.Bold)
			if name == "comment":
				format.setFontItalic(True)
			x0Highlighter.Formats[name] = format

	def highlightBlock(self, text):
		NORMAL, TRIPLESINGLE, TRIPLEDOUBLE = range(3)

		textLength = len(text)
		prevState = self.previousBlockState()

		self.setFormat(0, textLength, x0Highlighter.Formats["normal"])

		for regex, format in x0Highlighter.Rules:#素数测试
			i = regex.indexIn(text)
			while i >= 0:
				length = regex.matchedLength()
				self.setFormat(i, length, x0Highlighter.Formats[format])
				i = regex.indexIn(text, i + length)

		if not text:
			pass
		else:
			stack, pre = [], None
			for i, c in enumerate(text):
				if c == "/" and pre == c:
					self.setFormat(i-1, len(text)-i+1, x0Highlighter.Formats["comment"])
					break
				pre = c

		self.setCurrentBlockState(NORMAL)

	def rehighlight(self):
		QApplication.setOverrideCursor(QCursor(Qt.WaitCursor))
		QSyntaxHighlighter.rehighlight(self)
		QApplication.restoreOverrideCursor()

class x0Compiler(QMainWindow, UI_MainWindow):
	inputWrite = False
	def __init__(self):
		QMainWindow.__init__(self)
		UI_MainWindow.__init__(self)
		self.setupUi(self)
		self.runDlg = None
		self.highlighter = x0Highlighter(self.codeTextEdit.document())
		self.initUI()

	def onclick(self):
		self.inputWrite = True
		text = self.inputEdit.toPlainText()
		f = open("input.txt","w")
		f.write(text)
		f.close()
		self.inputEdit.clear()
		print("click")

	def errTbInit(self):
		'''
			This function is used to initialize the errMsgTable
		'''
		self.errorMsgTable.clear()
		self.errorMsgTable.setColumnCount(3)
		self.errorMsgTable.setRowCount(1)
		self.errorMsgTable.setHorizontalHeaderLabels(['errno', 'line', 'message'])
		self.errorMsgTable.verticalHeader().setVisible(False)
		self.errorMsgTable.setEditTriggers(QAbstractItemView.NoEditTriggers)
		self.errorMsgTable.setSelectionBehavior(QAbstractItemView.SelectRows)
		self.errorMsgTable.setColumnWidth(0, 70)
		self.errorMsgTable.setColumnWidth(2, 595)
		for idx in range(self.errorMsgTable.columnCount()):
			headItem = self.errorMsgTable.horizontalHeaderItem(idx)
			headItem.setForeground(QColor(0, 0, 0))

	def fileInit(self):
		self.filetag = False
		self.filepath = os.getcwd()
		self.filename = ""
		self.workPathLabel.setText("")
		cleanfiles()

	def initUI(self):
		self.fileInit()
		self.errTbInit()

		#self.scroll = QScrollArea()
		#self.scroll.setWidgrt(self.)
		self.actionNew.triggered.connect(self.newFile)
		self.actionOpen.triggered.connect(self.openFile)
		self.actionSave.triggered.connect(self.saveFile)
		self.actionBuildAndRun.triggered.connect(self.BuildAndRun)
		self.actionDebug.triggered.connect(self.DebugMod)
		self.linelabel.setText("")
		lines=""
		for num in range(1,23):
			lines=lines+str(num)
			if num < 22:
				lines=lines+'\n'			
			num=num+1
		self.linelabel.setText(lines)
		self.linelabel.setFixedWidth(30)
		font = QFont("Consolas",11,QFont.Normal)

		QFont.setLetterSpacing(font,QFont.AbsoluteSpacing,0.5)
		self.linelabel.setFont(font)
		self.outputLabel.setFont(font)
		self.tableWidget.setFont(font)
		self.label.setFont(font)
		self.codeTextEdit.setFont(font)
		
		self.label.setFixedWidth(280)
		self.label.setText("    pcode:\n")
		self.label.setAlignment(Qt.AlignTop)

		#设置表格属性：
		self.tableWidget.setObjectName("Variable Watches")
		self.tableWidget.setColumnCount(6)
		for i in range(6):		
			self.tableWidget.setColumnWidth(i,60)
		self.infoTabs.tabBar().setAutoFillBackground(True)

		#添加表头：
		list = ['idx','name','value','level','addr','size']
				
		for i in range(6):
			item = QTableWidgetItem(list[i])
			item.setBackground(QColor(13,13,13))
			self.tableWidget.setHorizontalHeaderItem(i, item)

		self.tableWidget.horizontalHeader().setStyleSheet("QHeaderView::section{background-color: #282923;}")
		self.tableWidget.horizontalHeader().setDefaultAlignment(QtCore.Qt.AlignCenter)
		
		self.commitButton.clicked.connect(self.onclick)
		self.show()

	def setBuildEnabled(self, ok):
		self.actionBuildAndRun.setEnabled(ok)
		self.actionDebug.setEnabled(ok)

	def startBuild(self):
		'''
			Preparation for build&run or debug a processing
		'''
		# clear output label and table contents
		self.label.setText("")
		self.outputLabel.setText("")
		
		self.tableWidget.clear()
		self.tableWidget.setRowCount(0);
		#添加表头：
		list = ['idx','name','value','level','addr','size']
				
		for i in range(6):
			item = QTableWidgetItem(list[i])
			item.setBackground(QColor(13,13,13))
			self.tableWidget.setHorizontalHeaderItem(i, item)

		self.tableWidget.horizontalHeader().setStyleSheet("QHeaderView::section{background-color: #282923;}")
		self.tableWidget.horizontalHeader().setDefaultAlignment(QtCore.Qt.AlignCenter)

		text = self.codeTextEdit.toPlainText()
		text.encode('utf-8')
		if text == "":
			text = u" "
		# If the current working codefile is existed, use it directly
		curfile = self.filepath+'\\'
		
		if self.filetag == True:
			curfile = curfile+self.filename
		# If the current working codefile is new, used a temporary file
		else:
			curfile = curfile+"~.tmp"
		
		codecs.open(curfile, 'w', 'utf-8').write(text)
		#os.system(os.getcwd()+"\\x0cpl.exe "+curfile)
		#os.system('./build.sh test0_simp.txt')
		import subprocess
		'''p = subprocess.Popen(['./demo','test0_simp.txt'], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		out, err = p.communicate()
		print(out)
		print(out)
		#output=commands.getstatusoutput('./demo test0_simp.txt')
		self.label.setText(out)'''

		file_output = open("debug.txt","w")
		if self.inputWrite == False :
			subprocess.Popen(["./demo",'testfile/'+self.filename],stdout = file_output).wait() ######输出重定向，不卡住界面也不会因输出而在生成exe时有问题，如果不需要等待子进程结束，去掉.wait即可
		elif self.inputWrite == True :
			file_input = open("input.txt") 
			openfile = "./demo testfile/%s"%self.filename
			print(self.filename)
			subprocess.Popen([openfile], stdin = file_input, stdout = file_output, shell = True).wait()
			file_input.close()
			self.inputWrite = False

		file_output.close()
		f = open("debug.txt","r")
		lines = f.readlines()
		flag = 0
		for line in lines:

			if flag == 0 and line == "pcode:\n":
				flag = 2
				line = "  " + line
			elif flag == 2 and re.search('Start',line)!=None:
				flag = 3
			elif line == "table:\n" and flag == 3:
				flag = 4
			elif flag == 4:
				flag = 1

			if flag == 2:
				pcodeText = self.label.text()
				pcodeText = '%s%s'%(pcodeText,line)
				#print(str)
				self.label.setText(pcodeText)
			elif flag == 1 and line.split != "":
				dataList = line.split()

				#插入一行
				rowCount = self.tableWidget.rowCount()
				self.tableWidget.insertRow(rowCount)
				self.tableWidget.setRowHeight(rowCount, 22)
				for i in range(0, 5):
					item = QTableWidgetItem(str(dataList[i]))
					item.setTextAlignment(Qt.AlignCenter)
					self.tableWidget.setItem(rowCount, i, item)

				text = ""
				for i in range(5, len(dataList)):
					if text != "" :
						text = text + ' '
					text = text + str(dataList[i])
				item = QTableWidgetItem(str(text))
				item.setTextAlignment(Qt.AlignCenter)
				self.tableWidget.setItem(rowCount, 5, item)

				
			elif flag == 3:
				outputText = self.outputLabel.text()
				outputText = '%s%s'%(outputText,line)
				self.outputLabel.setText(outputText)
		f.close()

	def runOver(self):
		self.setBuildEnabled(True)

	def errTbBuild(self):
		'''
			This function is to get error messages and fill the errorMsgTable
			return:  errNum
		'''
		errData = codecs.open(os.getcwd()+"\\ferr.json", 'r', 'utf-8').read()
		errData = json.loads(errData)

		idx = 0
		self.errTbInit()
		self.errorMsgTable.setItem(idx, 2, QTableWidgetItem(errData[u"total"]))
		for err in errData[u'errors']:
			self.errorMsgTable.insertRow(idx)
			self.errorMsgTable.setItem(idx, 0, QTableWidgetItem(err[u'typeno']))
			self.errorMsgTable.setItem(idx, 1, QTableWidgetItem(err[u'line']))
			self.errorMsgTable.setItem(idx, 2, QTableWidgetItem(err[u'message']))
			idx += 1
		return errData[u'errNum']

	def BuildAndRun(self):
		self.startBuild()

	def DebugMod(self):
		self.startBuild()
		
		if judge() == True:
			errNum = self.errTbBuild()
			if errNum == 0:
				self.runDlg = RuntimeWin(1, self)
				self.IOthread = threading.Thread(target=procRun,\
					args=(self.runDlg.codeList, self.runDlg))
				#self.IOthread.setDaemon('True')
				self.IOthread.start()
		else:
			QMessageBox.critical(self, "Critical", self.tr("Compiler processing error"))		

	def newFile(self):
		self.fileInit()
		self.codeTextEdit.setPlainText("")

	def openFile(self):
		dirO = QFileDialog.getOpenFileName(self, "Open Exist File", self.filepath + '/testfile', \
			"Text Files (*.txt)")
		dirO = dirO[0]
		if dirO != "":
			print(dirO)
			from os.path import isfile
			if isfile(dirO):
				text = codecs.open(dirO, 'r', 'utf-8').read()
				lineNum = text.count("\n")
				lines = ""
				for i in range(1,lineNum + 3):
					lines = lines + str(i) + '\n'
				self.linelabel.setText(lines)
				self.codeTextEdit.setPlainText(text)
				#dirO = str(dirO.toUtf8(), 'utf-8', 'ignore')
				self.filepath, self.filename = os.path.split(dirO)
				self.filetag = True
				self.workPathLabel.setText(self.filepath)

	def saveFile(self):
		text = self.codeTextEdit.toPlainText()
		#text = str(text.toUtf8, 'utf-8', 'ignore')
		print("save")
		if self.filetag == True:
			print(self.filepath+'\\'+self.filename)
			codecs.open(self.filepath+'\\'+self.filename, 'w', 'utf-8').write(text)
		else:
			dirS = QFileDialog.getSaveFileName(self, "Save File", self.filepath + '/testfile', \
				"x0 Files (*.x0);;Text Files (*.txt)")
			print(dirS)
			if dirS != "":
				print(dirS)
				codecs.open(dirS, 'w', 'utf-8').write(text)
				dirS = unicode(dirS.toUtf8(), 'utf-8', 'ignore')
				self.filepath, self.filename = os.path.split(dirS)
				self.filetag = True
				self.workPathLabel.setText(self.filepath)

	def closeEvent(self, event):
		if self.runDlg:
			self.runDlg.close()
		cleanfiles()

if __name__ == "__main__":
	app = QApplication(sys.argv)
	qApp.setStyleSheet(themeQss)
	window = x0Compiler()
	sys.exit(app.exec_())