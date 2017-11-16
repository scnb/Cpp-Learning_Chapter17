// 17-17.cpp : �������̨Ӧ�ó������ڵ㡣
//�򿪶���ļ��������д�����
/*
	���Ҫ���δ���һ���ļ����������ĳ��������10���ļ��г��ֵĴ���������������£����Դ�һ������
	���������ι�����ÿ���ļ���

	�����д�������
		C++��һ�����������л��������еĳ����ܹ����������в����Ļ��ƣ�������ʹ�����µ�main()������
		int main(int argc, char * argv[]);
		argcΪ�������еĲ������������а�������������
		argv��һ��ָ�����飬���е�ָ��ָ�������в�����
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::cerr;
using std::ifstream;

int main(int argc,char * argv[])
{
	if (argc == 1)
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin;
	long count;
	long total = 0;
	char ch;

	for (int file = 1;file < argc;file++)
	{
		fin.open(argv[file]);						//����������argv[file]��ϵ����
		if (!fin.is_open())							//is_open()��������ļ��Ƿ��
		{
			cerr << "Could not open " << argv[file] << endl;
			fin.clear();
			continue;
		}
		count = 0;
		while (fin.get(ch))							//�����ļ��е��ַ�����
		{
			count++;
		}
		cout << count << " charcter in " << argv[file] << endl;
		total += count;
		fin.clear();								//����ĳЩC++ʵ������Ҫ������
		fin.close();								//�����������ļ��Ͽ�����
	}
	cout << total << " characters in all files\n";
	system("pause");
    return 0;
}



