// 17-12.cpp : 定义控制台应用程序的入口点。
//											流状态
/*
	cin或cout对象包含一个描述流状态的数据成员。
	流状态由3个ios_base元素组成：eofbit、badbit或failbit，其中每个元素都是一位，可以是1（设置）或0（清除）
	①eofbit：cin操纵到达文件尾
	②badbit：一些无法诊断的失败破坏流
	③cin操作未能读取到预期的字符或I/O失败（如试图读取不可访问的文件或试图写入写保护的磁盘）。

	1、设置状态
	①clear()：将状态设置为它的参数
		clear()：使用默认参数0，清除全部3个状态。
		clear(eofbit)：eofbit将被设置，其他两个位将被清0
	②setstate()：该方法只影响其参数中已设置的位。
		setstate(eofbit)：该调用将eofbit设置为1，而不影响其他的位。
	2、I/O和异常
	exceptions()方法返回一个位字段，包含3位，分别对应于eofbit(),failbit(),badbit()
	修改流状态后，clear()方法将当前的流状态与exceptions()返回的值进行比较，如果在返回值中某一位被设置，而当前
	状态中的对应位也被设置，则clear()将引发ios_base::failure异常。
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	cin.exceptions(ios_base::failbit);			//使用failbit位来抛出一个异常
	cout << "Enter numbers: ";

	int sum = 0;
	int input;
	try
	{
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch (ios_base::failure & bf)
	{
		cout << bf.what() << endl;				//因为ios_base::failure异常类是从std::exception类派生而来的，因此包含一个what()方法。
		cout << "0! the horror!\n";
	}
	cout << "Last value entered = " << input << endl;			//last的意思是最后一个而不是上一个
	cout << "sum = " << sum << endl;
	system("pause");
	return 0;
}

