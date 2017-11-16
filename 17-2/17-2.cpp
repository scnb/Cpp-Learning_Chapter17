// 17-2.cpp : 定义控制台应用程序的入口点。
//cout的默认格式化输出：
/*
	①对于char值：如果它代表的是可打印字符，则将被作为一个字符显示在宽度为一个字符的字段中。
	②对于数值整型，将以十进制方式显示在一个刚好容纳该数字及负号（如果有的话）的字段中。
	③字符串显示在宽度等于该字符串长度的字段中。

	浮点数：
	浮点类型被显示为6位，末尾的0不显示。字段宽度恰好容纳数字和负号（如果有的话）。
	数字以定点表示法显示还是以科学计数法表示，取决于它的值。具体来说，当指数大于6或小于等于-5时，将使用科学计数法。
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "12345678901234567890\n";
	char ch = 'k';
	int t = 273;
	cout << ch << ":\n";						//输出字符k
	cout << t << ":\n";							//输出273
	cout << -t << ":\n";						//输出-273

	double f1 = 1.200;
	cout << f1 << ":\n";						//输出1.2
	cout << (f1 + 1.0 / 9.0) << ":\n";			//输出1.31111（一共六位）

	double f2 = 1.67e2;
	cout << f2 << ":\n";						//输出167
	f2 += 1.0 / 9.0;							
	cout << f2 << ":\n";						//输出167.111（一共6位）
	cout << (f2*1.0e4) << ":\n";				//输出1.67111e+6

	double f3 = 2.3e-4;
	cout << f3 << ":\n";						//输出0.00023
	cout << f3 / 10 << ":\n";					//输出2.3e-5
	getchar();
    return 0;
}

