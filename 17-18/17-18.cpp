// 17-18.cpp : 定义控制台应用程序的入口点。
//在文件尾追加数据
/*
	ios_base类定义了一个openmode模型，用于表示模式，是一种bitmask类型。
	可以选择ios_base类中定义的多个常量来指定模式。

	文件模式常量：
	常量								含义
	ios_base::in						打开文件，以便读取
	ios_base::out						打开文件，以便写入
	ios_base::ate						打开文件，并移到文件尾
	ios_base::app						追加到文件尾
	ios_base::trunc						如果文件存在，则截短文件
	ios_base::binary					二进制文件
	————————————————————————————————
	ios_base::app模式只允许将数据添加到文件尾，而ios_base::ate模式将指针放到文件尾。

	位运算符OR（|）可以将两个值合并成一个可用于同时设置两个位的值。

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

	if (fin.is_open())										//显示文件原来的数据
	{
		cout << "Here are the current contents of the " << file << " file:\n";
		while (fin.get(ch))
		{
			cout << ch;
		}
		fin.close();
	}
	ofstream fout(file, ios::out | ios::app);				//在文件尾添加数据
	if (!fout.is_open())
	{
		cerr << "Can't open " << file << " file for output.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter guest names (enter a blank line to quit):\n";
	string name;
	while (getline(cin, name) && name.size() > 0)
	{
		fout << name << endl;								//向文件中写入数据
	}
	fout.close();

	fin.clear();											//显示修改后的文件
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

