// 17-1.cpp : 定义控制台应用程序的入口点。
//ostream类中的put()方法和write()方法
/*
	put():用于显示字符
	write()：用于显示字符串  
	write()方法模板原型：
	basic_ostream<charT,traits> & write(const char_type* s,streamsize n)
	第一个参数提供了要显示的字符串的地址，第二个参数指出要显示多少个字符

	cout.write()调用返回cout对象，因为write()返回一个指向调用它的对象的引用

	！！注意：write()方法不会在遇到空字符时自动停止打印字符，而是打印指定数目的字符，即使超出了字符串的边界！
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	const char * state1 = "Florida";
	const char * state2 = "Kansas";
	const char * state3 = "Euphoria";
	int len = strlen(state2);

	cout << "Increasing loop index:\n";			//每次循环逐渐增加输出的字符个数
	int i;
	for (i = 0;i < len;i++)
	{
		cout.write(state2, i);
		cout << endl;
	}

	cout << "Decreasing loop index:\n";			//每次循环逐渐减少输出的字符个数
	for (i = len;i > 0;i--)
	{
		cout.write(state2, i) << endl;
	}

	cout << "Exceeding string length:\n";		//输出的字符个数超过字符串的长度
	cout.write(state2, len + 5) << endl;

	long val = 560031841;						//将数值数据的地址强制转换为char *，并显示
	cout.write((char *)&val, sizeof(long));
	getchar();
    return 0;
}

