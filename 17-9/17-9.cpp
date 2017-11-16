// 17-9.cpp : 定义控制台应用程序的入口点。
//setf()控制输出格式
/*
	第二种类型的setf()函数：
	fmtflags setf(fmtflags,fmtflags);			//函数的这种重载格式用于设置由多位控制的格式选项
	第一个参数包含了所需设置的fmtflags值，第二个参数指出要清除第一个参数中的哪些位（清除位）。

	ios_base为此定义了一批参数：

	第二个参数						第一个参数						含义
	~~~~~~~~~~~~~~~~~~~				ios_base::dec					以10为基数																
	ios_base::basefield				ios_base::hex					以16为基数
	____________________			ios_base::oct					以8为基数
									
	ios_base::floatfield			ios_base::fixed					使用定点计数法
	____________________			ios_base::scientific			使用科学计数法

									ios_base::left					使用左对齐
	ios_base::adjustfield			ios_base::right					使用右对齐
	_____________________			ios_base::internal				符号或基数前缀左对齐，值右对齐

	在C++标准中，定点表示法和科学表示法都有下面两个特征：
	①精度指的是小数位数，而不是总位数
	②显示末尾的0
*/			

#include "stdafx.h"
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	cout.setf(ios_base::left, ios_base::adjustfield);			//设置为左对齐
	cout.setf(ios_base::showpos);								//设置为显示正号
	cout.setf(ios_base::showpoint);								//设置为显示末尾的0
	cout.precision(3);											//设置精度——即小数位数为3
	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);		//设置以科学计数法输出
	cout << "Left Justification:\n";
	long n;
	for (n = 1;n <= 41;n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
	cout.setf(ios_base::internal, ios_base::adjustfield);		//设置为符号或基数前缀左对齐，值右对齐
	cout.setf(old, ios_base::floatfield);						//恢复原来的浮点数输出方式（默认表示方式）
	
	cout << "Internal Justification:\n";
	for (n = 1;n <= 41;n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	cout.setf(ios_base::right,ios_base::adjustfield);			//设置为右对齐
	cout.setf(ios_base::fixed, ios_base::floatfield);			//设置为定点表示法
	cout << "Right Justification:\n";
	for (n = 1;n <= 41;n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
	getchar();
    return 0;
}

