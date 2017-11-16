// 17-4.cpp : 定义控制台应用程序的入口点。
//
/*
	调整字段宽度：
	使用width()成员函数将长度不同的数字放到宽度相同的字段中。
	该方法的原型为：
	int width();			//返回字段宽度的当前设置
	int width(int i);		//将字段宽度设置为i个空格，并返回以前的字段宽度值（以便后面恢复原来的宽度）

	width()方法只影响接下来显示的一个项目，然后将字段宽度恢复为默认值。

	默认为右对齐，通过填充空格来充满整个字段。（用来填充的字符叫做填充字符）

	也可以改变填充字符，在默认情况下，填充字符是空格，通过调用fill()成员函数，来改变填充字符。
	例如：
		cout.fill('*');
	并且与width()方法不同的是，fill()方法的效果一直存在。

	特殊点：
			Ｃ＋＋永远不会截短数据，如果字段宽度不够，Ｃ＋＋将自动增宽字段。
			Ｃ／Ｃ＋＋的原则是：显示所有的数据比保持列的整洁更重要。
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	int w = cout.width(30);
	cout.fill('*');									//改变填充字符，默认为空格
	cout << "Default field width = " << w << endl;
	cout.width(5);
	cout << "N" << ':';
	cout.width(8);
	cout << "N*N" << ":\n";
	
	for (long i = 1;i <= 100;i *= 10)
	{
		cout.width(5);
		cout << i << ':';
		cout.width(8);
		cout << i*i << ":\n";
	}
	getchar();
    return 0;
}

