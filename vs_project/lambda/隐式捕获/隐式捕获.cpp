//��ʽ����

#include <iostream>
using namespace std;

class test
{
public:
	void hello() {
		cout << "test hello!\n";
	};
	void lambda() {
		auto fun = [this] { // ������ this ָ��
			this->hello(); // ���� this ���õľ��� class test �Ķ�����
		};
		fun();
	}
};

int main()
{
	//��ʾ����
	cout << "/*******��ʾ����*******/" << endl;
	int i = 12;		cout << &i << endl;					//�����010FF834	//012��8���ƣ�ʮ������10��
	auto func = [i] { cout << &i << " " << i << endl; };
	func();                                 // �����010FF828 12

	cout << endl;

	//��ʽ����
	cout << "/*******��ʽ����*******/" << endl;

	[](int j) { cout << &j << " " << j << endl; }(23);      //��ͨ���������塱����ġ�()���������
	cout << endl;

	cout << "1.��������" << endl;
	int a = 123; cout << &a << endl;         //�����010FF81C
	auto f = [=] { cout << &a << " " << a << endl; };
	f();                                     //�����010FF810 123
	cout << endl;

	cout << "2.���ò���" << endl;
	int b = 234;
	auto f_1 = [&] { cout << &b << " " << b << endl; };
	b = 345; cout << &b << endl;				//�����010FF804
	f_1();                                    //�����010FF804 345
	cout << endl;

	cout << "3.���������û��" << endl;
	//[&, x]������x��������ʽ������������Դ�ֵ��ʽ����
	int c = 456, d = 567;
	cout << &c << " " << &d << endl;          //�����010FF7EC 010FF7E0
	auto f_2 = [=, &d] {
		cout << &c << " " << &d << " " << c << " " << d << endl;       //�����010FF7D4 010FF7E0 456 567
	};
	f_2();
	cout << endl;

	cout << "4.[bar] ָ�����û򿽱�" << endl;
	int e = 678;    cout << &e << endl;       //�����010FF7C4
	auto f_3 = [e] { cout << &e << " " << e << endl; };
	f_3();									  // �����010FF7B8 678
	cout << endl;

	cout << "5.[this] ���� this ָ��" << endl;
	//����Ҫ����������
	test t;
	t.lambda();


	return 0;
}


