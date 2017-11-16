// 17-17.cpp : 定义控制台应用程序的入口点。
//打开多个文件和命令行处理技术
/*
	如果要依次处理一组文件，例如计算某个名称在10个文件中出现的次数，在这种情况下，可以打开一个流，
	并将它依次关联到每个文件。

	命令行处理技术：
		C++有一种让在命令行环境中运行的程序能够访问命令行参数的机制，方法是使用如下的main()函数：
		int main(int argc, char * argv[]);
		argc为命令行中的参数个数，其中包括命令名本身。
		argv是一个指针数组，其中的指针指向命令行参数。
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::cerr;
using std::ifstream;

int main(int argc,char * argv[])
{
	if (argc == 1)
	{
		cerr << "Usage: " << argv[0] << " filename[s]\n";
		exit(EXIT_FAILURE);
	}

	ifstream fin;
	long count;
	long total = 0;
	char ch;

	for (int file = 1;file < argc;file++)
	{
		fin.open(argv[file]);						//将输入流与argv[file]联系起来
		if (!fin.is_open())							//is_open()方法检测文件是否打开
		{
			cerr << "Could not open " << argv[file] << endl;
			fin.clear();
			continue;
		}
		count = 0;
		while (fin.get(ch))							//计算文件中的字符个数
		{
			count++;
		}
		cout << count << " charcter in " << argv[file] << endl;
		total += count;
		fin.clear();								//对于某些C++实现是需要该语句的
		fin.close();								//将输入流与文件断开连接
	}
	cout << total << " characters in all files\n";
	system("pause");
    return 0;
}



