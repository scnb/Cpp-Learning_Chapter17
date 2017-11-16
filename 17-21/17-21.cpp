// 17-21.cpp : �������̨Ӧ�ó������ڵ㡣
//�ں˸�ʽ����incore formatting������ȡstring�����еĸ�ʽ����Ϣ�򽫸�ʽ����Ϣд��string�����б���Ϊ�ں˸�ʽ��
/*
	ͷ�ļ�sstream������һ����ostrema������������ostringstream�࣬���������һ��ostringstream��������Խ�����Ϣ
	д�����У������洢��Щ��Ϣ�����Խ�������cout�ķ�������ostrngstream����

	ostringstream����һ��str()��Ա�������ú�������һ������ʼ��Ϊ���������ݵ��ַ�������
		ostringstream outstr;
		string msg = outstr.str();
*/

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::ios_base;
using std::ostringstream;						//ͷ�ļ�sstream������һ����ostream������������ostringstream��

int main()
{
	ostringstream outstr;						//����һ��string��
	string hdisk;
	cout << "What's the name of your hard disk? ";
	getline(cin, hdisk);
	int cap;
	cout << "What's its capacity in GB? ";		//Ӳ�������Ǽ�GB
	cin >> cap;
	outstr << "The hard disk " << hdisk << " has a capacity of " << cap << " gigabytes.\n";
	string result = outstr.str();				//����result���󣬷���һ������ʼ��Ϊ���������ݵ��ַ�������
	cout << result;								//��ʾ����
	getchar();
	getchar();
    return 0;
}

