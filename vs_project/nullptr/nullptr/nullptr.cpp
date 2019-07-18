/*
nullptr ���ֵ�Ŀ����Ϊ����� NULL����ĳ����������˵����ͳ C++ ��� NULL��0 ��Ϊͬһ�ֶ�����
��ȡ���ڱ�������ζ��� NULL����Щ�������Ὣ NULL ����Ϊ((void*)0)����Щ���ֱ�ӽ��䶨��Ϊ 0��
*/

#include <iostream>
void foo(char *);
void foo(int);
int main() {

	if (NULL == (void *)0) std::cout << "NULL == 0" << std::endl;
	else std::cout << "NULL != 0" << std::endl;

	foo(0);
	//foo(NULL); // G++�����޷�ͨ�� //������֪������ foo(char *)���� foo(int); //����IDE��ͨ����
	foo(nullptr);

	return 0;
}
void foo(char *ch) {
	std::cout << "call foo(char*)" << std::endl;
}
void foo(int i) {
	std::cout << "call foo(int)" << std::endl;
}