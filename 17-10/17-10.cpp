// 17-10.cpp : �������̨Ӧ�ó������ڵ㡣
//ͷ�ļ�iomanip
/*
	C++��ͷ�ļ�iomanip���ṩ������һЩ���Ʒ��������ܹ��ṩ֮ǰ�����е���Щ���ܣ�����ʾ���������㡣
	3����õĿ��Ʒ��ֱ���setprecision()��setfill()��setw()���ֱ��������þ��ȡ�����ַ����ֶο�ȡ�

	setprecision()���Ʒ�����һ��ָ�����ȵ���������
	setfill()���Ʒ�����һ��ָ������ַ���char����
	setw()���Ʒ�����һ��ָ���ֶο�ȵ���������
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	cout << std::fixed << endl;				//ʹ���±�׼�Ŀ��Ʒ�
	cout << std::setw(6) << 'N' << std::setw(14) << "square root" << std::setw(15) << "fourth root\n";	//ʹ��iomanip�еĿ��Ʒ�
	double root;
	for (int n = 10;n <= 100;n += 10)
	{
		root = sqrt(double(n));
		cout << std::setw(6) << std::setfill('.') << n << std::setfill(' ') << std::setw(12) << std::setprecision(3) << root << std::setw(14) << std::setprecision(4) << sqrt(root) << endl;
	}
	getchar();
    return 0;
}

