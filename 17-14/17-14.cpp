// 17-14.cpp : �������̨Ӧ�ó������ڵ㡣
//

/*
	peek()�������������е���һ���ַ���������ȡ���ַ���
	putback()������һ���ַ����뵽�����ַ����У���������ַ�����һ���������ĵ�һ���ַ���
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	char ch;							//��ȡ���ҷ����ַ���ֱ������һ��#�ַ�
	while (cin.get(ch))
	{
		if (ch != '#')
		{
			cout << ch;
		}
		else
		{
			cin.putback(ch);			//��#�ַ����뵽ԭ������������
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

	while (cin.peek() != '#')									//����������������һ���ַ��Ƿ���#�ַ���������ǣ����ȡ����ʾ���ַ�
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

