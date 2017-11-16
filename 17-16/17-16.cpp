// 17-16.cpp : 定义控制台应用程序的入口点。
//文件输入和输出
/*
	简单的文件I/O：
	1、让程序写入文件：
		①创建一个ofstream对象来管理输出流			例如：
		②将该对象与特定的文件相连接				使用open()方法，例如：fout.open("test.txt")
		③以使用cout的方式使用该对象

	2、让程序读取文件：
		①创建一个ifstream对象来管理输出流
		②将该对象与特定的文件关联起来
		③以使用cin的方式使用该对象
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
	ofstream fout(filename.c_str());		//为新文件创建一个输出流对象，并且命名为fout
	fout << "For your eyes only!\n";
	cout << "Enter your secret number: ";
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();							//显式关闭文件与输入流的连接

	ifstream fin(filename.c_str());			//为新文件创建一个输入流对象，并且命名为fin
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

