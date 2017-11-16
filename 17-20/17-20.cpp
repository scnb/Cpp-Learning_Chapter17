// 17-20.cpp : �������̨Ӧ�ó������ڵ㡣
//�����ȡ��
/*
	�����ȡָ����ֱ���ƶ����ļ�������λ�á�

�Զ�дģʽ���ļ����Ա��ܹ���ȡ���޸ļ�¼�����Դ���һ��fstream����fstream���Ǵ�iostream�����������ģ�
	��iostream���ֻ���ifstream��ofstream�����ࡣ��ˣ���fstream����̳������ǵķ�����ͬʱ���̳�������������
	��һ�����뻺������һ�����������������ͬ���Ż��������������Ĵ���
	���磺
		finout.open(file,ios_base::in|ios_base::out|ios_base::binary);

����Ҫһ�����ļ����ƶ��ķ�ʽ��fstream��Ϊ�˼̳�������������
	��seekg()��������ָ���ƶ���ָ�����ļ�λ��
	
	��seekp()�������ָ���ƶ���ָ�����ļ�λ��

	��1��seekg()��ԭ�ͣ�
		��basic_istream<charT,traits>& seekg(off_type,ios_base::seekdir); //��λ����ڶ�������ָ�����ļ�λ���ض�����
			������char���廯��istream & seekg(streamoff,ios_base::seekdir);
				streamoff����������������ļ��ض�λ�õ�ƫ����
				seekdir��ios_base�ж������һ�����ͣ���3�����ܵ�ֵ��
				�ٳ���ios_base::beg  ָ������ļ���ʼ����ƫ����
				�ڳ���ios_base::cur  ָ����ڵ�ǰλ�õ�ƫ����
				�۳���ios_base::end	 ָ������ļ�β��ƫ����

		��basic_istream<charT,traits>& seekg(pos_type);					  //��λ�����ļ���ͷ�ض������λ��
			������char���廯��istream & seekg(streampos)
				streampos���͵�ָ��λ���ļ��е�һ��λ�á�
				streamposֵ���Կ�����������ļ���ʼ���ľ���λ�á����Ե�λΪ�ֽڣ���һ���ֽڵı��Ϊ0��
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

	fstream finout;						//��ʾԭʼ��Ϣ
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);				//���ļ�ָ���ƶ����ļ���ͷ
		cout << "Here are the contents of " << file << " file:\n";
		while (finout.read((char *)&pl, sizeof(pl)))
		{
			cout << ct++ << ": " << setw(LIM) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
		}
		if (finout.eof())
		{
			finout.clear();				//���eof��־λ
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

	cout << "Enter the record number you wish to change: ";			//�ı�һ����¼
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "Invalid record number - - bye\n";
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof(pl);								//��recת����streampos����
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "Error on attempted seek\n";
		exit(EXIT_FAILURE);
	}
	finout.read((char *)&pl, sizeof(pl));							//��ȡָ��λ�õ�����
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
	finout.seekg(0);						//���ļ�ָ���ƶ����ļ���ͷ
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

