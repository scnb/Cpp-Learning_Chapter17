// 17-6.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
	���ø���������ʾ���ȣ�
			���������ȵĺ���ȡ�������ģʽ��
			����Ĭ��ģʽ�£���ָ������ʾ����λ����
			���ڶ���ģʽ�Ϳ�ѧģʽ�£�����ָ����С��������λ����

			C++��Ĭ�Ͼ�����6λ��

			precession()��Ա�����ܹ�����Ϊ����ֵ��
			���磬��cout�ľ�������Ϊ2��
			cout.precession(2);

			�µľ������ý�һֱ��Ч��ֱ�����������á�
	��ӡĩβ��0��С���㣺
			iostream��û���ṩר�����������������ĺ�������ios_base���ṩ��һ��setf()�������ܹ����ƶ���
			��ʽ�����ԡ�
			
			���磺����ĺ�������ʹcout��ʾĩβС����
			cout.setf(ios_base::showpoint);
			���У�showpoint��ios_base�������ж�����༶��̬������
			�༶��ζ������ڳ�Ա�������������ʹ������������ڳ�����ǰ������������������
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;

	cout.setf(ios_base::showpoint);								//��ʾĩβ��0��С����

	cout << "\"Furry Friends\" is $" << price1 << "!\n";
	cout << "\"Fiery Friends\" is $" << price2 << "!\n";

	cout.precision(2);
	cout << "\"Furry Friends\" is $" << price1 << "!\n";
	cout << "\"Fiery Friends\" is $" << price2 << "!\n";
	getchar();
    return 0;
}

