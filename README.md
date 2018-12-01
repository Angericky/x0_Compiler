# x0_Compiler

### Description
A x0 language compiler with UI, written in C and PyQt, using Lex &amp; Yacc tool. The x0 language syntax is like C mixed with PL/0.

### UI
You can easily find how to build and run a file written in x0 by UI.
The user interface looks like:
![Image discription](https://github.com/Angericky/x0_Compiler/blob/master/image/image/UI.png)

### Bonus  
**bonus required:**
1. 增加运算符（各2分）
	* ☑求余运算符% 
	* ☑异或运算符XOR 
	* ☑判断整数的奇偶ODD 
	* ☑自增++，自减-- 
2. 增加语句，语法参照C语言
	* ☑switch…case语句（5分）
	* ☑for语句（5分）
	* ☑continue，exit，break语句（6分）
	* ☑do…while语句（2分）
	* ☑repeat…until语句(2分)
3. 增加基本数据类型
	* ☑可扩充到支持布尔数据类型，应支持and，or，not等布尔数据运算(10分)
	* ☑可扩充到支持实数数据类型，实现+、-、*、/等运算。可以采用两种方案：
	一种是整数类型和实数类型等不允许“混合使用”，但存在两种数据类型的转换操作符；另一种是允许“混合使用”，如当运算结果赋给整型变量时候则自动取整。(12分)
4. 增加常量(const)的定义与使用（4分）
	* ☑区分变量与常量，可以参考PL/0语言中的实现方法
5. 扩充成多维数组（10分左右，视实际情况给分）
	* ☑增加由任何数据类型构造的多维数组，允许定义数组、对数组元素赋值、在表达式中引用数组元素等。
6. 允许调用(call)过程(8分左右，视实际情况给分)
	* ☑可以参考PL/0语言中的实现方法，也可以参考C语言中的实现方法
7. 扩充带参数、返回值的过程(15分左右，视实际情况给分)
	* ☑比较容易实现的一种模式是数值参数(call by value)：调用的实际参数是表达式，它在调用时被算出具体的值。形式参数表示过程的局部变量，它在调用时被赋予相应的实际参数值。此外还可以使用地址参数(call by reference)。过程还可以有返回值。

**other bonus:**
  1. 支持定义语句
   e.g. int a = 10;

  2. 支持一句中连续声明、定义、read多个变量（包括数组）
   e.g. read a[1],a[2];

  3. * 支持有大括号及单句的for循环
     * 支持有大括号及单句的while循环
     * 支持有大括号及单句的do_while循环
     * 支持有大括号及单句的repeat_until循环

  4. 支持操作符% != == >= <= > <

  5. 支持单行与多行注释 /**/与//

### Error symbol table
 
Error number |  Description
---- | -----
11 | 调用函数时使用一个未声明过的变量
12 | 对类型不是char、int、float、boolean的变量进行定义的赋值
15 | 调用非函数：call一个不是procedure类型的变量
35 | 使用了未定义的变量名
36 | read proc类型的变量
37 | 连续read proc类型的变量
38 | 对类型不是char、int、float、bool的变量进行write操作
40 | 使用系统未定义关键字进行声明
41 | 数组访问越界
44 | 对非数组进行x[]形式的操作
50 | 对负数进行sqrt
51 | 对除了boolean、char、int、float以外的类型进行输入
52 | 对除了int、float之外的类型进行取负、相加、相乘、相减
53 | 进行了类型不同且不能强制类型转换的赋值
54 | 对非整数进行取余、取逆、求平方根
55 | 对非boolean类型进行and not or操作                                     
56 | boolrean类型赋值非true或false   
