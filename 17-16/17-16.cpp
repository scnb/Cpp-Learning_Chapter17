// 17-16.cpp : �������̨Ӧ�ó������ڵ㡣
//�ļ���������
/*
	�򵥵��ļ�I/O��
	1���ó���д���ļ���
		�ٴ���һ��ofstream���������������			���磺
		�ڽ��ö������ض����ļ�������				ʹ��open()���������磺fout.open("test.txt")
		����ʹ��cout�ķ�ʽʹ�øö���

	2���ó����ȡ�ļ���
		�ٴ���һ��ifstream���������������
		�ڽ��ö������ض����ļ���������
		����ʹ��cin�ķ�ʽʹ�øö���
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

int main()
{
	string filename;
	cout << "Enter name for new file: ";
	cin >> filename;
	ofstream fout(filename.c_str());		//Ϊ���ļ�����һ����������󣬲�������Ϊfout
	fout << "For your eyes only!\n";
	cout << "Enter your secret number: ";
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();							//��ʽ�ر��ļ���������������

	ifstream fin(filename.c_str());			//Ϊ���ļ�����һ�����������󣬲�������Ϊfin
	cout << "Here are the contents of " << filename << ":\n";
	char ch;
	while (fin.get(ch))
	{
		cout << ch;
	}
	cout << "Done.\n";
	fin.close();
	getchar();
	getchar();
    return 0;
}

