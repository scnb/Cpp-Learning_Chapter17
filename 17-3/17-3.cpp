// 17-3.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
	�޸���ʾʱʹ�õļ���ϵͳ��
	ios_base��洢��������ʽ״̬����Ϣ����ios_base����������ios�࣬�ִ�ios����������ostream�ࡣ
	ͨ��ʹ�ÿ��Ʒ���manipulator�������Կ�����ʾ����ʱʹ�õļ���ϵͳ��
	ͨ��ʹ��ios_base�ĳ�Ա���������Կ����ֶο�Ⱥ�С��λ����

	���磺
		Ҫ����������8���ơ�10���ƻ�16������ʾ������ʹ��dec��hex��oct���Ʒ���
		hex(cout);
		��cout<<hex;	cout��������<<���������ʹ�������÷��뺯������hex(cout)�ȼ�

	���Ʒ�λ�����ƿռ�std�С�
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "Enter an integer: ";
	int n;
	cin >> n;

	cout << "n		n*n\n";
	cout << n << "		" << n*n << "(decimal)\n";

	cout << std::hex;											//����Ϊ16����ģʽ��hex���Ʒ���std�ռ���
	cout << n << "		";
	cout << n*n << "(hexadecimal)\n";

	cout << std::oct << n << "		" << n*n << "(octal)\n";	//����Ϊ8����ģʽ��oct���Ʒ�Ҳ��std�ռ���

	dec(cout);													//��һ���л�ģʽ�ķ���
	cout << n << "		" << n*n << "(decimal)\n";				
	getchar();
	getchar();
    return 0;
}

