// 17-21.cpp : 定义控制台应用程序的入口点。
//内核格式化（incore formatting）：读取string对象中的格式化信息或将格式化信息写入string对象中被称为内核格式化
/*
	头文件sstream定义了一个从ostrema类派生而来的ostringstream类，如果创建了一个ostringstream对象，则可以将这信息
	写入其中，它将存储这些信息。可以将可用于cout的方法用于ostrngstream对象。

	ostringstream类有一个str()成员函数，该函数返回一个被初始化为缓冲区内容的字符串对象：
		ostringstream outstr;
		string msg = outstr.str();
*/

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::ios_base;
using std::ostringstream;						//头文件sstream定义了一个从ostream类派生而来的ostringstream类

int main()
{
	ostringstream outstr;						//管理一个string流
	string hdisk;
	cout << "What's the name of your hard disk? ";
	getline(cin, hdisk);
	int cap;
	cout << "What's its capacity in GB? ";		//硬盘容量是几GB
	cin >> cap;
	outstr << "The hard disk " << hdisk << " has a capacity of " << cap << " gigabytes.\n";
	string result = outstr.str();				//保存result对象，返回一个被初始化为缓冲区内容的字符串对象
	cout << result;								//显示内容
	getchar();
	getchar();
    return 0;
}

