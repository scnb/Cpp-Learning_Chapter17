// 17-8.cpp : �������̨Ӧ�ó������ڵ㡣
//ʹ��setf()�����������ʽ
/*
	ios_base����һ���ܱ��������ݳ�Ա�����еĸ�λ��������ǣ��ֱ�����Ÿ�ʽ���ĸ������档

	��һ����ǳ�Ϊ���ñ�ǣ���λ��������ζ����Ӧ��λ������Ϊ1��

	setf()����������ԭ�ͣ�
		��1��
			fmtflags setf(fmtflags);		//fmtflags��bitmask���͵�typedef���������ڴ洢��ʽ��ǡ�
			�ð汾��setf()�������õ���λ���Ƶĸ�ʽ��Ϣ��
			������һ��fmtflags��ָ��Ҫ������һλ��
			����ֵ������Ϊfmtflags�����֣�ָ�����б����ǰ�����á�

			Ϊ�˷��㣬ios_base���ж����˴���λֵ�ĳ�����
	��ʽ������
		����								����
		ios_base::boolalpha					��������boolֵ������Ϊtrue��false
		ios_base::showbase					���������ʹ��C++����ǰ׺��0��0x��
		ios_base::showpoint					��ʾĩβ��С����
		ios_base::uppercase					����16���������ʹ�ô�д��ĸ��E��ʾ��
		ios_base::showpos					������ǰ�����+����������Ϊ10ʱ��
	bitmask������һ�������洢����λֵ�����͡������������͡�ö�١�Ҳ������STL bitset������
	ÿһλ�����Ե������ʣ������Լ��ĺ��塣
*/

#include "stdafx.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	int temperature = 63;
	cout << "Today's water temperature: ";
	cout.setf(ios_base::showpos);						//��ʾ����
	cout << temperature << endl;

	cout << "For our programming friends,that's\n";
	cout << std::hex << temperature << endl;			//ʹ��16�������
	cout.setf(ios_base::uppercase);						//ʹ�ô�д���
	cout.setf(ios_base::showbase);						//��ǰ׺���
	cout << "or\n";
	cout << temperature << endl;
	cout << "How " << true << "! oops -- now ";
	cout.setf(ios_base::boolalpha);						//���boolֵ����true��false��
	cout << true << "!\n";
	getchar();
    return 0;
}

