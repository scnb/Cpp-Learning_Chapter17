// 17-1.cpp : �������̨Ӧ�ó������ڵ㡣
//ostream���е�put()������write()����
/*
	put():������ʾ�ַ�
	write()��������ʾ�ַ���  
	write()����ģ��ԭ�ͣ�
	basic_ostream<charT,traits> & write(const char_type* s,streamsize n)
	��һ�������ṩ��Ҫ��ʾ���ַ����ĵ�ַ���ڶ�������ָ��Ҫ��ʾ���ٸ��ַ�

	cout.write()���÷���cout������Ϊwrite()����һ��ָ��������Ķ��������

	����ע�⣺write()�����������������ַ�ʱ�Զ�ֹͣ��ӡ�ַ������Ǵ�ӡָ����Ŀ���ַ�����ʹ�������ַ����ı߽磡
*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	const char * state1 = "Florida";
	const char * state2 = "Kansas";
	const char * state3 = "Euphoria";
	int len = strlen(state2);

	cout << "Increasing loop index:\n";			//ÿ��ѭ��������������ַ�����
	int i;
	for (i = 0;i < len;i++)
	{
		cout.write(state2, i);
		cout << endl;
	}

	cout << "Decreasing loop index:\n";			//ÿ��ѭ���𽥼���������ַ�����
	for (i = len;i > 0;i--)
	{
		cout.write(state2, i) << endl;
	}

	cout << "Exceeding string length:\n";		//������ַ����������ַ����ĳ���
	cout.write(state2, len + 5) << endl;

	long val = 560031841;						//����ֵ���ݵĵ�ַǿ��ת��Ϊchar *������ʾ
	cout.write((char *)&val, sizeof(long));
	getchar();
    return 0;
}

