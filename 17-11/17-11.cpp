// 17-11.cpp : �������̨Ӧ�ó������ڵ㡣
//ʹ��cin��������
/*
	cin����׼�����ʾΪ�ֽ�����
	cin������ݽ���ֵ�ı��������ͣ�ʹ���䷽�����ַ�����ת��Ϊ��������͡�
	
	ͨ������������ʹ��cin����
		cin>>value_holder;

	value_holderΪ�洢������ڴ浥Ԫ���������Ǳ��������á���������õ�ָ�룬Ҳ���������ṹ�ĳ�Ա��
	istream�������˳�ȡ�����>>��ʹ֮���Դ������»������ͣ�
		signed char &
		unsigned char &
		char &
		short &
		unsigned short &
		int &
		unsigned int &
		long &
		unsigned long &
		long long &
		unsigned long long &
		float &
		double &
		long double &
	��Щ�������������Ϊ��ʽ�����뺯����formatted input functions�������ǽ���������ת��ΪĿ��ָ���ĸ�ʽ��

	���͵����������ԭ�����£�
		istream & operator<<(int &);			//�����ͷ���ֵ��������
		����>>��������Ըı������ֵ

	��������Ļ������ͣ�istream�໹Ϊ�ַ�ָ������������>>��ȡ�������
		signed char *
		char *
		unsigned char *
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	cout << "Enter numbers: ";

	int sum = 0;
	int input;
	while (cin >> input)
	{
		sum += input;
	}

	cout << "Last value entered = " << input << endl;			//last����˼�����һ����������һ��
	cout << "sum = " << sum << endl;
	system("pause");
    return 0;
}

