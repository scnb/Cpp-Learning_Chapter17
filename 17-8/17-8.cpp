// 17-8.cpp : 定义控制台应用程序的入口点。
//使用setf()来控制输出格式
/*
	ios_base类有一个受保护的数据成员，其中的各位（称作标记）分别控制着格式化的各个方面。

	打开一个标记称为设置标记（或位），并意味着相应的位被设置为1。

	setf()函数有两个原型：
		（1）
			fmtflags setf(fmtflags);		//fmtflags是bitmask类型的typedef别名，用于存储格式标记。
			该版本的setf()用来设置单个位控制的格式信息。
			参数是一个fmtflags，指出要设置哪一位。
			返回值是类型为fmtflags的数字，指出所有标记以前的设置。

			为了方便，ios_base类中定义了代表位值的常量。
	格式常量：
		常量								含义
		ios_base::boolalpha					输入和输出bool值，可以为true或false
		ios_base::showbase					对于输出，使用C++基数前缀（0，0x）
		ios_base::showpoint					显示末尾的小数点
		ios_base::uppercase					对于16进制输出，使用大写字母，E表示法
		ios_base::showpos					在整数前面加上+（仅当基数为10时）
	bitmask类型是一种用来存储各个位值的类型。它可以是整型、枚举、也可以是STL bitset容器。
	每一位都可以单独访问，都有自己的含义。
*/

#include "stdafx.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	int temperature = 63;
	cout << "Today's water temperature: ";
	cout.setf(ios_base::showpos);						//显示正号
	cout << temperature << endl;

	cout << "For our programming friends,that's\n";
	cout << std::hex << temperature << endl;			//使用16进制输出
	cout.setf(ios_base::uppercase);						//使用大写输出
	cout.setf(ios_base::showbase);						//带前缀输出
	cout << "or\n";
	cout << temperature << endl;
	cout << "How " << true << "! oops -- now ";
	cout.setf(ios_base::boolalpha);						//输出bool值（即true或false）
	cout << true << "!\n";
	getchar();
    return 0;
}

