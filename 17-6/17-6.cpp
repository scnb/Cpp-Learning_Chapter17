// 17-6.cpp : 定义控制台应用程序的入口点。
//
/*
	设置浮点数的显示精度：
			浮点数精度的含义取决于输出模式：
			①在默认模式下，它指的是显示的总位数。
			②在定点模式和科学模式下，精度指的是小数点后面的位数。

			C++的默认精度是6位。

			precession()成员函数能够设置为其他值。
			例如，将cout的精度设置为2：
			cout.precession(2);

			新的精度设置将一直有效，直到被重新设置。
	打印末尾的0和小数点：
			iostream类没有提供专门用于完成这项任务的函数，但ios_base类提供了一个setf()函数，能够控制多种
			格式化特性。
			
			例如：下面的函数调用使cout显示末尾小数点
			cout.setf(ios_base::showpoint);
			其中，showpoint是ios_base类声明中定义的类级静态常量。
			类级意味着如果在成员函数定义的外面使用它，则必须在常量名前面加上作用域运算符。
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;

	cout.setf(ios_base::showpoint);								//显示末尾的0和小数点

	cout << "\"Furry Friends\" is $" << price1 << "!\n";
	cout << "\"Fiery Friends\" is $" << price2 << "!\n";

	cout.precision(2);
	cout << "\"Furry Friends\" is $" << price1 << "!\n";
	cout << "\"Fiery Friends\" is $" << price2 << "!\n";
	getchar();
    return 0;
}

