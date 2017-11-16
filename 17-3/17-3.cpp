// 17-3.cpp : 定义控制台应用程序的入口点。
//
/*
	修改显示时使用的技术系统：
	ios_base类存储了描述格式状态的信息。从ios_base类派生出了ios类，又从ios类派生出了ostream类。
	通过使用控制符（manipulator），可以控制显示整数时使用的计数系统。
	通过使用ios_base的成员函数，可以控制字段宽度和小数位数。

	例如：
		要控制整数以8进制、10进制或16进制显示，可以使用dec、hex和oct控制符。
		hex(cout);
		或cout<<hex;	cout类重载了<<运算符，这使得上述用法与函数调用hex(cout)等价

	控制符位于名称空间std中。
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "Enter an integer: ";
	int n;
	cin >> n;

	cout << "n		n*n\n";
	cout << n << "		" << n*n << "(decimal)\n";

	cout << std::hex;											//设置为16进制模式，hex控制符在std空间中
	cout << n << "		";
	cout << n*n << "(hexadecimal)\n";

	cout << std::oct << n << "		" << n*n << "(octal)\n";	//设置为8进制模式，oct控制符也在std空间中

	dec(cout);													//另一种切换模式的方法
	cout << n << "		" << n*n << "(decimal)\n";				
	getchar();
	getchar();
    return 0;
}

