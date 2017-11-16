// 17-15.cpp : 定义控制台应用程序的入口点。
//使用peek()来确定是否读取了整行，如果没有的话，就把输入流中的其他字符都删掉。

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

const int SLEN = 10;

inline void eatline() { while (cin.get() != '\n') continue; }

int main()
{
	char name[SLEN];
	char title[SLEN];
	cout << "Enter your name: ";
	cin.get(name, SLEN);
	if (cin.peek() != '\n')
	{
		cout << "Sorry,we only have enough room for " << name << endl;
	}
	eatline();
	cout << "Dear " << name << ", enter your title: \n";
	cin.get(title, SLEN);
	if (cin.peek() != '\n')
	{
		cout << "We were forced to truncate your title.\n";
	}
	eatline();
	cout << " Name: " << name << "\nTitle: " << title << endl;
	getchar();
	getchar();
    return 0;
}

