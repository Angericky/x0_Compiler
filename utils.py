#!/usr/bin/python                                                                                                                                                      
# -*- coding: utf-8 -*

import time

class Instruction(object):
	def __init__(self, f, l, a):
		self.f = f
		self.l = l
		self.a = a

class Interpret(object):
	def __init__(self, taclist):
		self.code = taclist
		self.paramInit()

	def paramInit(self):
		self.buf = None
		self.c = 0		# current code index
		self.p = 0		# pointer of code
		self.b = 1		# base address of code
		self.t = 0		# pointer of stack top
		# runtime stack
		self.s = [0 for x in xrange(5000)]
		self.reg = [0 for x in xrange(16)]

	def judge(self):
		if self.p == 0:
			return False
		return True

	def base(self, l, b):
		b1 = b
		while l > 0:
			b1 = self.s[b1]
			l -= 1
		return b1

	def send(self, data):
		self.s[self.t] = data

	def recv(self):
		return self.buf

	def showStack(self):
		return [self.s[x] for x in xrange(self.t+1)]

	def sg_step(self):
		p, b, t = self.p, self.b, self.t
		s, reg = self.s, self.reg
		self.c = p
		'''
		 tag is for judge IO
		 0 means common operation
		 1 means input
		 2 means output
		'''
		tag = 0
		i = self.code[p]
		p += 1

		if i.f == "lit":
			t += 1
			s[t] = i.a
		if i.f == "opr":
			if i.a == 0:	#return
				t = b - 1
				p = s[t + 3]
				b = s[t + 2]
			if i.a == 1:	# inverse
				s[t] = -s[t]
			if i.a == 2:	# plus
				t = t - 1
				s[t] = s[t] + s[t + 1]
			if i.a == 3:	# minus
				t = t - 1
				s[t] = s[t] - s[t + 1]
			if i.a == 4:	# times
				t = t - 1
				s[t] = s[t] * s[t + 1]
			if i.a == 5:
				t = t - 1
				if i.l == 0:	# slash
					s[t] = s[t] / s[t + 1]
				if i.l == 1:	# mod
					s[t] = s[t] % s[t + 1]
			if i.a == 6:	# odd
				s[t] = s[t] & 1
			if i.a == 7:
				t = t - 1
				if i.l == 0:	# equal
					s[t] = (s[t] == s[t + 1])
				if i.l == 1:	# not equal
					s[t] = (s[t] != s[t + 1])
			if i.a == 8:
				t = t - 1
				if i.l == 0:	# less
					s[t] = (s[t] < s[t + 1])
				if i.l == 1:	# less or equal
					s[t] = (s[t] <= s[t + 1])
			if i.a == 9:
				t = t - 1
				if i.l == 0:	# larger
					s[t] = (s[t] > s[t + 1])
				if i.l == 1:	# larger or equal
					s[t] = (s[t] >= s[t + 1])
			if i.a == 10:	# bitwise and
				t = t - 1
				s[t] = s[t] & s[t + 1]
			if i.a == 11:	# bitwise or
				t = t - 1
				s[t] = s[t] | s[t + 1]
			if i.a == 12:	# bitwise not
				s[t] = ~s[t]
			if i.a == 13:	# xor
				t = t - 1
				s[t] = s[t] ^ s[t + 1]
			if i.a == 14:	# logic and
				t = t - 1
				s[t] = (s[t] and s[t + 1])
			if i.a == 15:	# logic or
				t = t - 1
				s[t] = (s[t] or s[t + 1])
			if i.a == 16:	# shift operation
				t = t - 1
				if i.l == 0:
					s[t] = s[t] << s[t + 1]
				if i.l == 1:
					s[t] = s[t] >> s[t + 1]
		if i.f == "lod":	# push value from memory into stack
			t = t + 1
			s[t] = s[self.base(i.l, b) + i.a]
		if i.f == "sto":	# save the stack top value
			s[self.base(i.l, b) + i.a] = s[t]
			t = t - 1
		if i.f == "cal":	# call function
			s[t + 1] = self.base(i.l, b)
			s[t + 2] = b
			s[t + 3] = p
			b = t + 1
			p = i.a
		if i.f == "int":	# initialize a size data space
			t = t + i.a
		if i.f == "jmp":	# unconditional jump
			p = i.a
			tag = 3
		if i.f == "jne":	# not-equal conditional jump
			if s[t] == 0:
				p = i.a
			t = t - 1
		if i.f == "jeq":	# equal conditional jump
			if s[t] != 0:
				p = i.a
			t = t - 1
		if i.f == "in":		# input
			t = t + 1
			if i.a == 0:
				tag = 1
			else:
				s[t] = reg[i.a]
		if i.f == "out":	# output
			if i.a == 0:
				self.buf = s[t]
				tag = 2
			else:
				reg[i.a] = s[t]
			t = t - 1

		self.p, self.b, self.t = p, b, t
		self.s, self.reg = s, reg
		return tag