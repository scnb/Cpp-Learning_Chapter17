// 17-13.cpp : �������̨Ӧ�ó������ڵ㡣
//�ַ������룺get(),getline()��ignore()
/*
	����ԭ�ͣ�
	istream & get(char *,int,char);
	istream & get(char *,int);
	istream & getline(char *,int,char);
	istream & getline(char *,int);

	��һ�����������ڷ��������ַ������ڴ浥Ԫ�ĵ�ַ���ڶ��������Ƕ�ȡ����ַ�����1��Ҫ�������ڽ�β�Ŀ��ַ���
	����������ָ�������ֽ�����ַ���

	get()��getline()����Ҫ�������ڣ�get()�����з�/�ֽ�������������У���getline()��ȡ�������������еĻ��з�/�ֽ����
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

