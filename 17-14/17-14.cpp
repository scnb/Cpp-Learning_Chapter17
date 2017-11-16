// 17-14.cpp : 定义控制台应用程序的入口点。
//

/*
	peek()函数返回输入中的下一个字符，但不抽取该字符。
	putback()函数将一个字符插入到输入字符串中，被插入的字符是下一条输入语句的第一个字符。
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	char ch;							//读取并且返回字符，直到遇到一个#字符
	while (cin.get(ch))
	{
		if (ch != '#')
		{
			cout << ch;
		}
		else
		{
			cin.putback(ch);			//将#字符插入到原来的输入流中
			break;
		}
	}

	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";
		exit(0);
	}

	while (cin.peek() != '#')									//程序检查输入流中下一个字符是否是#字符，如果不是，则读取并显示该字符
	{
		cin.get(ch);
		cout << ch;
	}

	if (!cin.eof())
	{
		cin.get(ch);
		cout << endl << ch << " is next input character.\n";
	}
	else
	{
		cout << "End of file reached.\n";
	}
	getchar();
	getchar();
    return 0;
}

