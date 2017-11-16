// 17-13.cpp : 定义控制台应用程序的入口点。
//字符串输入：get(),getline()和ignore()
/*
	函数原型：
	istream & get(char *,int,char);
	istream & get(char *,int);
	istream & getline(char *,int,char);
	istream & getline(char *,int);

	第一个参数是用于放置输入字符串的内存单元的地址，第二个参数是读取最大字符数加1（要保存用于结尾的空字符）
	第三个参数指定用作分界符的字符。

	get()和getline()的主要区别在于：get()将换行符/分界符留在输入流中，而getline()抽取并丢弃输入流中的换行符/分界符。
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

const int Limit = 255;

int main()
{
	char input[Limit];

	cout << "Enter a string for getline() processing:\n";
	cin.getline(input, Limit, '#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 1\n";

	char ch;
	cin.get(ch);
	cout << "The next input character is " << ch << endl;

	if (ch != '\n')
	{
		cin.ignore(Limit, '\n');
	}

	cout << "Enter a string for get() processing:\n";
	cin.get(input, Limit, '#');
	cout << "Here is your input:\n";
	cout << input << "\nDone with phase 2\n";

	cin.get(ch);
	cout << "The next input character is " << ch << endl;
	getchar();
	getchar();
    return 0;
}

