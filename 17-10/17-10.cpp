// 17-10.cpp : 定义控制台应用程序的入口点。
//头文件iomanip
/*
	C++在头文件iomanip中提供了其他一些控制符，它们能够提供之前程序中的那些功能，但表示起来更方便。
	3个最常用的控制符分别是setprecision()、setfill()和setw()，分别用来设置精度、填充字符和字段宽度。

	setprecision()控制符接受一个指定精度的整数参数
	setfill()控制符接受一个指定填充字符的char参数
	setw()控制符接受一个指定字段宽度的整数参数
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	cout << std::fixed << endl;				//使用新标准的控制符
	cout << std::setw(6) << 'N' << std::setw(14) << "square root" << std::setw(15) << "fourth root\n";	//使用iomanip中的控制符
	double root;
	for (int n = 10;n <= 100;n += 10)
	{
		root = sqrt(double(n));
		cout << std::setw(6) << std::setfill('.') << n << std::setfill(' ') << std::setw(12) << std::setprecision(3) << root << std::setw(14) << std::setprecision(4) << sqrt(root) << endl;
	}
	getchar();
    return 0;
}

