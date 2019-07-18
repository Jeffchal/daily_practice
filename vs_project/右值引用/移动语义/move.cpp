//��ͳ C++ ͨ���������캯���͸�ֵ������Ϊ���������˿��� / ���Ƶĸ��
//��Ϊ��ʵ�ֶ���Դ���ƶ������������߱���ʹ���ȸ��ơ��������ķ�ʽ���������Ҫ�Լ�ʵ���ƶ�����Ľӿڡ�
//���룬��ҵ�ʱ���ǰѼ���Ķ���ֱ�Ӱᵽ�¼�ȥ�������ǽ����ж�������һ�ݣ������ٷŵ��¼ҡ�
//�ٰ�ԭ���Ķ���ȫ�����٣����Ƿǳ��������һ�����顣
//
//��ͳ�� C++ û�����֡��ƶ����͡��������ĸ������˴����������ƶ����˷�ʱ��Ϳռ䡣
//��ֵ���õĳ���ǡ�þͽ��������������Ļ�������

//#include <iostream>
//
//class A {
//public:
//	int *pointer;
//	A() :pointer(new int(1)) {
//		std::cout << "����" << pointer << std::endl;
//	}
//	// ������Ķ��󿽱�
//	A(A& a) :pointer(new int(*a.pointer)) {
//		std::cout << "����" << pointer << std::endl;
//	}
//
//	A(A&& a) :pointer(a.pointer) {
//		a.pointer = nullptr;
//		std::cout << "�ƶ�" << pointer << std::endl;
//	}
//
//	~A() {
//		std::cout << "����" << pointer << std::endl;
//		delete pointer;
//	}
//};
//// ��ֹ�������Ż�
//A return_rvalue(bool test) {
//	A a, b;							 // �٣��������� A �������ǻ���������캯�������;
//	if (test) return a;
//	else return b;			        // �ڣ��������غ󣬲���һ������ֵ����ΪҪ����ֵobj�����Ա� A ���ƶ����죨A(A&&)������
//									//�Ӷ��ӳ��������ڣ����������ֵ�е�ָ���õ������浽�� obj �У�������ֵ��ָ�뱻����Ϊ nullptr��
//									//��ֹ������ڴ��������١�
//}
//int main() {
//	A obj = return_rvalue(false);
//	std::cout << "obj:" << std::endl;
//
//	std::cout << obj.pointer << std::endl;
//	std::cout << *obj.pointer << std::endl;
//
//	return 0;
//}


//���������漰��׼������ӣ�
#include <iostream> // std::cout
#include <utility>  // std::move
#include <vector>   // std::vector
#include <string>   // std::string

int main() {

	std::string str = "Hello world.";
	std::vector<std::string> v;

	// ��ʹ�� push_back(const T&), ������������Ϊ
	v.push_back(str);
	// ����� "str: Hello world."
	std::cout << "str: " << str << std::endl;

	// ��ʹ�� push_back(const T&&), ������ֿ�����Ϊ
	// �������ַ����ᱻ�ƶ��� vector �У�������ʱ�� std::move ���������ٿ������ֵĿ���
	// �ⲽ������, str �е�ֵ���Ϊ��
	v.push_back(std::move(str));
	// ����� "str: "
	std::cout << "str: " << str << std::endl;

	return 0;
}

