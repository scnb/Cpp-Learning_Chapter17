// 17-20.cpp : 定义控制台应用程序的入口点。
//随机存取：
/*
	随机存取指的是直接移动到文件的任意位置。

以读写模式打开文件，以便能够读取和修改记录。可以创建一个fstream对象，fstream类是从iostream类派生而来的，
	而iostream类又基于ifstream和ofstream两个类。因此，该fstream对象继承了它们的方法，同时还继承了两个缓冲区
	，一个输入缓冲区，一个输出缓冲区，并能同步优化这两个缓冲区的处理。
	例如：
		finout.open(file,ios_base::in|ios_base::out|ios_base::binary);

还需要一种在文件中移动的方式：fstream类为此继承了两个方法：
	①seekg()：将输入指针移动到指定的文件位置
	
	②seekp()：将输出指针移动到指定的文件位置

	（1）seekg()的原型：
		①basic_istream<charT,traits>& seekg(off_type,ios_base::seekdir); //定位到离第二个参数指定的文件位置特定距离
			·对于char具体化：istream & seekg(streamoff,ios_base::seekdir);
				streamoff被用来度量相对于文件特定位置的偏移量
				seekdir是ios_base中定义的另一种整型，有3个可能的值：
				①常量ios_base::beg  指相对于文件开始处的偏移量
				②常量ios_base::cur  指想对于当前位置的偏移量
				③常量ios_base::end	 指相对于文件尾的偏移量

		②basic_istream<charT,traits>& seekg(pos_type);					  //定位到离文件开头特定距离的位置
			·对于char具体化：istream & seekg(streampos)
				streampos类型的指定位到文件中的一个位置。
				streampos值可以看作是相对于文件开始处的绝对位置。（以单位为字节，第一个字节的编号为0）
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ios;
using std::ios_base;
using std::cerr;
using std::fixed;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::setprecision;
using std::streampos;
using std::streamoff;
using std::flush;

const int LIM = 20;

struct Planet
{
	char name[LIM];
	double population;
	double g;
};

const char * file = "planets.dat";
inline void eatline() { while (cin.get() != '\n')continue; }

int main()
{
	Planet pl;
	cout << fixed;

	fstream finout;						//显示原始信息
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);				//将文件指针移动到文件开头
		cout << "Here are the contents of " << file << " file:\n";
		while (finout.read((char *)&pl, sizeof(pl)))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
		{
			finout.clear();				//清除eof标志位
		} 
		else
		{
			cerr << "Error in reading " << file << ".\n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << "Could not be openned - - bye.\n";
		exit(EXIT_FAILURE);
	}

	cout << "Enter the record number you wish to change: ";			//改变一条记录
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "Invalid record number - - bye\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof(pl);								//将rec转换成streampos类型
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "Error on attempted seek\n";
		exit(EXIT_FAILURE);
	}
	finout.read((char *)&pl, sizeof(pl));							//读取指定位置的数据
	cout << "Your selection: \n";
	cout << rec << ": " << setw(LIM) << pl.name << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
	if (finout.eof())
	{
		finout.clear();
	}
	cout << "Enter planet name: ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "Enter planet population: ";
	cin >> pl.population;
	cout << "Enter planet's acceleration of gravity: ";
	cin >> pl.g;
	finout.seekg(place);
	finout.write((char *)&pl, sizeof(pl)) << flush;
	if (finout.fail())
	{
		cerr << "Error on attempted write.\n";
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);						//将文件指针移动到文件开头
	cout << "Here are the contents of the " << file << " file.\n";
	while (finout.read((char *)&pl, sizeof(pl)))
	{
		cout << ct++ << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "Done.\n";
	getchar();
	getchar();
    return 0;
}

