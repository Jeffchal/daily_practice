// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// test.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������
#include <iostream>
using namespace  std;

int main()
{
	char ch[]={"abc\0def"};
	char *p=ch;

	cout << *p+4 <<endl;             //���101��a+4��ת��Ϊ97+4
	cout << *(p+4) <<endl;           //���d �� pָ��ch[4]

	return 0;
}