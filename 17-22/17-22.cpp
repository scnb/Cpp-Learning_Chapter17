// 17-22.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
	istringstream������ʹ��istream�������ȡistringstream�����е����ݣ�istringstream�������ʹ��string
	������г�ʼ����

*/

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::ios_base;
using std::istringstream;
using std::string;

int main()
{
	string lit = "It was a dark and stormy day, and the full moon glowed brilliantly. ";
	istringstream instr(lit);
	string word;
	while (instr >> word)
	{
		cout << word << endl;
	}
	getchar();
    return 0;
}

