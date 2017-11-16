// 17-19.cpp : �������̨Ӧ�ó������ڵ㡣
//�ı���ʽ�Ͷ����Ƹ�ʽ��
/*
	�ı���ʽ���ڶ�ȡ������ʹ�ñ༭�����Ӵ���������ȡ�ͱ༭�ı��ļ������Ժܷ���ؽ��ı��ļ���һ�������ϵͳ
	���䵽��һ�������ϵͳ��
	�����Ƹ�ʽ����������˵�ȽϾ�ȷ����Ϊ���洢����ֵ���ڲ���ʾ,��˲�����ת������������

	Ҫ�ö����Ƹ�ʽ�洢��Ϣ��������������
	ofstream fout(file,ios_base::out|ios_base::app|ios_base::binary); 
	fout.write((char *)&pl,sizeof(pl));
	��������ʹ�ü�������ڲ���ʾ�����������ݽṹ��Ϊһ�����屣�档���ܽ����ļ���Ϊ�ı���ȡ�������ı���ȣ���Ϣ��
	�����Ϊ���գ���ȷ��

	Ҫ�Զ����Ƹ�ʽ�洢���ݣ�����ʹ��write()���������з������ڴ���ָ����Ŀ���ֽڸ��Ƶ��ļ��С�

	setw�趨�ֶο�ȣ�setprecision�趨���ȡ�

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

inline void eatline() { while (cin.get() != '\n')continue; }			//��ȡ�����������л��з�֮ǰ������

struct Planet
{
	char name[20];						//��������
	double population;					//�����˿�
	double g;							//���ٶ�
};

const char * file = "planets.dat";		//�ļ�����

int main()
{
	Planet pl;
	cout << fixed << endl;
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);						//��ʾԭʼ����Ϣ
	if (fin.is_open())
	{
		cout << "Here are the current contents of the " << file << " file:\n";
		while (fin.read((char *)&pl, sizeof(pl)))
		{
			cout << setw(20) << pl.name << ": " << setprecision(0) << setw(12) << pl.population << setprecision(2) << setw(6) << pl.g << endl;
		}
		fin.close();
	}
	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);	//�������Ϣ
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

	fin.clear();											//��ʾ���ĺ���ļ�
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

