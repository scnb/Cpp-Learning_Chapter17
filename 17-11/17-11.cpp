// 17-11.cpp : 定义控制台应用程序的入口点。
//使用cin进行输入
/*
	cin将标准输入表示为字节流。
	cin对象根据接收值的变量的类型，使用其方法将字符序列转换为所需的类型。
	
	通常，可以这样使用cin对象：
		cin>>value_holder;

	value_holder为存储输入的内存单元，它可以是变量、引用、被解除引用的指针，也可以是类或结构的成员。
	istream类重载了抽取运算符>>，使之可以处理如下基本类型：
		signed char &
		unsigned char &
		char &
		short &
		unsigned short &
		int &
		unsigned int &
		long &
		unsigned long &
		long long &
		unsigned long long &
		float &
		double &
		long double &
	这些运算符函数被称为格式化输入函数（formatted input functions），它们将输入数据转化为目标指定的格式。

	典型的运算符函数原型如下：
		istream & operator<<(int &);			//参数和返回值都是引用
		所以>>运算符可以改变变量的值

	除了上面的基本类型，istream类还为字符指针类型重载了>>抽取运算符：
		signed char *
		char *
		unsigned char *
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "Enter numbers: ";

	int sum = 0;
	int input;
	while (cin >> input)
	{
		sum += input;
	}

	cout << "Last value entered = " << input << endl;			//last的意思是最后一个而不是上一个
	cout << "sum = " << sum << endl;
	system("pause");
    return 0;
}

