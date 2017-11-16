// 17-18.cpp : �������̨Ӧ�ó������ڵ㡣
//���ļ�β׷������
/*
	ios_base�ඨ����һ��openmodeģ�ͣ����ڱ�ʾģʽ����һ��bitmask���͡�
	����ѡ��ios_base���ж���Ķ��������ָ��ģʽ��

	�ļ�ģʽ������
	����								����
	ios_base::in						���ļ����Ա��ȡ
	ios_base::out						���ļ����Ա�д��
	ios_base::ate						���ļ������Ƶ��ļ�β
	ios_base::app						׷�ӵ��ļ�β
	ios_base::trunc						����ļ����ڣ���ض��ļ�
	ios_base::binary					�������ļ�
	����������������������������������������������������������������
	ios_base::appģʽֻ����������ӵ��ļ�β����ios_base::ateģʽ��ָ��ŵ��ļ�β��

	λ�����OR��|�����Խ�����ֵ�ϲ���һ��������ͬʱ��������λ��ֵ��

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::cerr;
using std::string;

const char * file = "guests.txt";

int main()
{
	char ch;
	ifstream fin;
	fin.open(file);

	if (fin.is_open())										//��ʾ�ļ�ԭ��������
	{
		cout << "Here are the current contents of the " << file << " file:\n";
		while (fin.get(ch))
		{
			cout << ch;
		}
		fin.close();
	}
	ofstream fout(file, ios::out | ios::app);				//���ļ�β�������
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter guest names (enter a blank line to quit):\n";
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << name << endl;								//���ļ���д������
	}
	fout.close();

	fin.clear();											//��ʾ�޸ĺ���ļ�
	fin.open(file);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the " << file << " file:\n";
		while (fin.get(ch))
		{
			cout << ch;
		}
		fin.close();
	}
	cout << "Done.\n";
	getchar();
    return 0;
}

