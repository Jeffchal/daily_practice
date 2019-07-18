//#include <iostream>
//
//template<typename T>
//class aTMP {
//public:
//	void f1() { std::cout << "f1()\n"; }
//	void f2() { std::ccccout << "f2()\n"; } // �ô�����ˣ��������û�� std::ccccout
//};
//
//int main() {
//	aTMP<int> a;
//	a.f1();
//	//a.f2(); // �����뱻ע��ʱ��aTMP<int>::f2() ����ʵ�������Ӷ�����Ĵ����ڸ�!
//
//	return 0;
//}

#include <iostream>

// ���� N �Ľ׳� N!
template<int N>
class aTMP {
public:
	enum { ret = N == 0 ? 1 : N * aTMP<N - 1>::ret }; // Lazy Instantiation�����������޵ݹ�!
};
template<>
class aTMP<0> {
public:
	enum { ret = 1 };
};

int main() {
	std::cout << aTMP<10>::ret << '\n';
	
	return 0;
}