//�޸Ĳ������
#include <iostream>
using namespace std;

int main()
{
	int a = 123; cout << &a << endl;
	auto f = [a]()mutable {cout << ++a <<endl; };//���ᱨ��
	cout << a << endl;//���123
	f();//���124
	cout << &a << endl;
}