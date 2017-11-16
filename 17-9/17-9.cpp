// 17-9.cpp : �������̨Ӧ�ó������ڵ㡣
//setf()���������ʽ
/*
	�ڶ������͵�setf()������
	fmtflags setf(fmtflags,fmtflags);			//�������������ظ�ʽ���������ɶ�λ���Ƶĸ�ʽѡ��
	��һ�������������������õ�fmtflagsֵ���ڶ�������ָ��Ҫ�����һ�������е���Щλ�����λ����

	ios_baseΪ�˶�����һ��������

	�ڶ�������						��һ������						����
	~~~~~~~~~~~~~~~~~~~				ios_base::dec					��10Ϊ����																
	ios_base::basefield				ios_base::hex					��16Ϊ����
	____________________			ios_base::oct					��8Ϊ����
									
	ios_base::floatfield			ios_base::fixed					ʹ�ö��������
	____________________			ios_base::scientific			ʹ�ÿ�ѧ������

									ios_base::left					ʹ�������
	ios_base::adjustfield			ios_base::right					ʹ���Ҷ���
	_____________________			ios_base::internal				���Ż����ǰ׺����룬ֵ�Ҷ���

	��C++��׼�У������ʾ���Ϳ�ѧ��ʾ��������������������
	�پ���ָ����С��λ������������λ��
	����ʾĩβ��0
*/			

#include "stdafx.h"
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	cout.setf(ios_base::left, ios_base::adjustfield);			//����Ϊ�����
	cout.setf(ios_base::showpos);								//����Ϊ��ʾ����
	cout.setf(ios_base::showpoint);								//����Ϊ��ʾĩβ��0
	cout.precision(3);											//���þ��ȡ�����С��λ��Ϊ3
	ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);		//�����Կ�ѧ���������
	cout << "Left Justification:\n";
	long n;
	for (n = 1;n <= 41;n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
	cout.setf(ios_base::internal, ios_base::adjustfield);		//����Ϊ���Ż����ǰ׺����룬ֵ�Ҷ���
	cout.setf(old, ios_base::floatfield);						//�ָ�ԭ���ĸ����������ʽ��Ĭ�ϱ�ʾ��ʽ��
	
	cout << "Internal Justification:\n";
	for (n = 1;n <= 41;n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	cout.setf(ios_base::right,ios_base::adjustfield);			//����Ϊ�Ҷ���
	cout.setf(ios_base::fixed, ios_base::floatfield);			//����Ϊ�����ʾ��
	cout << "Right Justification:\n";
	for (n = 1;n <= 41;n += 10)
	{
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
	getchar();
    return 0;
}

