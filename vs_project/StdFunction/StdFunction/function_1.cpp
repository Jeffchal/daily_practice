//#include <iostream>
//
//using foo = void(int);  // ���庯��ָ��, using ��ʹ�ü���һ���еı����﷨
//void functional(foo f) {
//	f(2);                  
//}
//
//int main() {
//	auto f = [](int value) {
//		std::cout << value << std::endl;
//	};
//	functional(f);  // ����ָ�����,�����뺯���ڲ�			�����2
//	f(1);           // lambda ���ʽ����					�����1
//	return 0;
//}

//C++11 std::function ��һ��ͨ�á���̬�ĺ�����װ������ʵ�����Զ��κο��Ե��õ�Ŀ��ʵ����д洢�����ƺ͵��ò�����
//��Ҳ�Ƕ� C++�����еĿɵ���ʵ���һ�����Ͱ�ȫ�İ����������˵������ָ��ĵ��ò������Ͱ�ȫ�ģ���
//���仰˵�����Ǻ��������������������˺���������֮����ܹ����ӷ���Ľ�����������ָ����Ϊ������д���
#include <functional>
#include <iostream>

int foo(int para) {
	return para;
}

int main() {

	int a = 123; 
	a += 1;
	int b = 220;
	auto f = [=] { std::cout << a << std::endl; };
	f();                                     //�����124
	std::cout << std::endl;


	// std::function ��װ��һ������ֵΪ int, ����Ϊ int �ĺ���
	std::function<int(int)> func = foo;

	int important = 10;
	std::function<int(int)> func2 = [&](int value) -> int {           //[&]��[=]
		return 1 + value + important;
	};
	std::cout << func(10) << std::endl;		//�����10
	std::cout << func2(10) << std::endl;	//�����21
}