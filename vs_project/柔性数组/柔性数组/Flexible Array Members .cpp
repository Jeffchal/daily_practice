#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>

struct test
{
	int a = 10;			    //  4+4(��)����Ϊdouble����Ҫ��8����������ʼ
	double  b = 20.0;		//  8+8
	char c = 'a';			//  8+8+1+3(��)����ΪInt����Ҫ��4����������ʼ
	int d = 30;				//  8+8+4+4 = 24
	char e = 'e';			//  24+1+7(��)
	char f = 'f';			//  ���ڶ���Ԫ�ص�ַ
	char buf[];				//  �������ڶ���Ԫ�ص�ַ+���ֽڳ�+1
};


int main(int *argc, int **argv)
{
	char ch[] = "hello world!";
	std::cout << sizeof(ch) << std::endl;

	//struct test tst;
	//tst.buf = ch;		   // ����ָ���������͡�char []��, ���ʽ�����ǿ��޸ĵ���ֵ

	struct test* p = (struct test*)malloc(sizeof(struct test) + sizeof(ch) + 1);
	strcpy_s(p->buf, sizeof(ch) + 1, ch);
	std::cout << "�ṹ���С" <<sizeof(*p) << std::endl;
	std::cout << "�ṹ���׵�ַ" << p << " �ṹ��β��ַ " << (p + 1) << std::endl;

	std::cout  << &p->a << std::endl;
	std::cout  << &p->b << std::endl;
	std::cout  << (void *) &p->c << std::endl;
	std::cout  << &p->d << std::endl;
	std::cout  << (void *) &(p->e) << std::endl;
	std::cout  << (void *) &(p->f) << std::endl;
	std::cout  << "���������ַ/ֵ " << &p->buf << " " << p->buf << std::endl;
	free(p);

	return 0;
}