// 17-15.cpp : �������̨Ӧ�ó������ڵ㡣
//ʹ��peek()��ȷ���Ƿ��ȡ�����У����û�еĻ����Ͱ��������е������ַ���ɾ����

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

