// 17-12.cpp : �������̨Ӧ�ó������ڵ㡣
//											��״̬
/*
	cin��cout�������һ��������״̬�����ݳ�Ա��
	��״̬��3��ios_baseԪ����ɣ�eofbit��badbit��failbit������ÿ��Ԫ�ض���һλ��������1�����ã���0�������
	��eofbit��cin���ݵ����ļ�β
	��badbit��һЩ�޷���ϵ�ʧ���ƻ���
	��cin����δ�ܶ�ȡ��Ԥ�ڵ��ַ���I/Oʧ�ܣ�����ͼ��ȡ���ɷ��ʵ��ļ�����ͼд��д�����Ĵ��̣���

	1������״̬
	��clear()����״̬����Ϊ���Ĳ���
		clear()��ʹ��Ĭ�ϲ���0�����ȫ��3��״̬��
		clear(eofbit)��eofbit�������ã���������λ������0
	��setstate()���÷���ֻӰ��������������õ�λ��
		setstate(eofbit)���õ��ý�eofbit����Ϊ1������Ӱ��������λ��
	2��I/O���쳣
	exceptions()��������һ��λ�ֶΣ�����3λ���ֱ��Ӧ��eofbit(),failbit(),badbit()
	�޸���״̬��clear()��������ǰ����״̬��exceptions()���ص�ֵ���бȽϣ�����ڷ���ֵ��ĳһλ�����ã�����ǰ
	״̬�еĶ�ӦλҲ�����ã���clear()������ios_base::failure�쳣��
*/

#include "stdafx.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios_base;

int main()
{
	cin.exceptions(ios_base::failbit);			//ʹ��failbitλ���׳�һ���쳣
	cout << "Enter numbers: ";

	int sum = 0;
	int input;
	try
	{
		while (cin >> input)
		{
			sum += input;
		}
	}
	catch (ios_base::failure & bf)
	{
		cout << bf.what() << endl;				//��Ϊios_base::failure�쳣���Ǵ�std::exception�����������ģ���˰���һ��what()������
		cout << "0! the horror!\n";
	}
	cout << "Last value entered = " << input << endl;			//last����˼�����һ����������һ��
	cout << "sum = " << sum << endl;
	system("pause");
	return 0;
}

