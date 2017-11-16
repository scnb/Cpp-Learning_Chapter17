// 17-22.cpp : 定义控制台应用程序的入口点。
//
/*
	istringstream类允许使用istream方法族读取istringstream对象中的数据，istringstream对象可以使用string
	对象进行初始化。

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

