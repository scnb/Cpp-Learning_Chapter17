// 17-4.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
	�����ֶο��ȣ�
	ʹ��width()��Ա���������Ȳ�ͬ�����ַŵ�������ͬ���ֶ��С�
	�÷�����ԭ��Ϊ��
	int width();			//�����ֶο��ȵĵ�ǰ����
	int width(int i);		//���ֶο�������Ϊi���ո񣬲�������ǰ���ֶο���ֵ���Ա����ָ�ԭ���Ŀ��ȣ�

	width()����ֻӰ���������ʾ��һ����Ŀ��Ȼ���ֶο��Ȼָ�ΪĬ��ֵ��

	Ĭ��Ϊ�Ҷ��룬ͨ�����ո������������ֶΡ������������ַ���������ַ���

	Ҳ���Ըı�����ַ�����Ĭ������£�����ַ��ǿո�ͨ������fill()��Ա���������ı�����ַ���
	���磺
		cout.fill('*');
	������width()������ͬ���ǣ�fill()������Ч��һֱ���ڡ�

	����㣺
			�ã�����Զ����ض����ݣ�����ֶο��Ȳ������ã������Զ������ֶΡ�
			�ã��ã�����ԭ���ǣ���ʾ���е����ݱȱ����е��������Ҫ��
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;


int main()
{
	int w = cout.width(30);
	cout.fill('*');									//�ı�����ַ���Ĭ��Ϊ�ո�
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
