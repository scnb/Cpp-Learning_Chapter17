// 17-19.cpp : 定义控制台应用程序的入口点。
//文本格式和二进制格式：
/*
	文本格式便于读取，可以使用编辑器或子处理器来读取和编辑文本文件，可以很方便地将文本文件从一个计算机系统
	传输到另一个计算机系统。
	二进制格式对于数字来说比较精确，因为它存储的是值的内部表示,因此不会有转换误差或舍入误差。

	要用二进制格式存储信息，可以这样做：
	ofstream fout(file,ios_base::out|ios_base::app|ios_base::binary); 
	fout.write((char *)&pl,sizeof(pl));
	上述代码使用计算机的内部表示，将整个数据结构作为一个整体保存。不能将该文件作为文本读取，但与文本相比，信息的
	保存更为紧凑，精确。

	要以二进制格式存储数据，可以使用write()函数，这中方法将内存中指定数目的字节复制到文件中。

	setw设定字段宽度，setprecision设定精度。

*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::fixed;
using std::ifstream;
using std::ios_base;
using std::setw;
using std::setprecision;
using std::ofstream;

inline void eatline() { while (cin.get() != '\n')continue; }			//读取并丢弃输入中换行符之前的内容

struct Planet
{
	char name[20];						//行星名字
	double population;					//行星人口
	double g;							//加速度
};

const char * file = "planets.dat";		//文件名称

int main()
{
	Planet pl;
	cout << fixed << endl;
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);						//显示原始的信息
	if (fin.is_open())
	{
		cout << "Here are the current contents of the " << file << " file:\n";
		while (fin.read((char *)&pl, sizeof(pl)))
		{
			cout << setw(20) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);	//添加新信息
	if (!fout.is_open())
	{
		std::cerr << "Can't open " << file << " file for output:\n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter planet name (enter a blank line to quit):\n";
	cin.get(pl.name, 20);
	while (pl.name[0] != '\0')
	{
		eatline();
		cout << "Enter planetary population: ";
		cin >> pl.population;
		cout << "Enter planet's acceleration of gravity: ";
		cin >> pl.g;
		eatline();
		fout.write((char *)&pl, sizeof(pl));
		cout << "Enter planet name (enter a blank line to quit):\n";
		cin.get(pl.name, 20);
	}
	fout.close();

	fin.clear();											//显示更改后的文件
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the contents of the " << file << " file:\n";
		while (fin.read((char *)&pl, sizeof(pl)))
		{
			cout << setw(20) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}
	cout << "Done.\n";
	getchar();
	getchar();
    return 0;
}

