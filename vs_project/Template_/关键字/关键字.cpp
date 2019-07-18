#include <iostream>

template<typename T>
class aTMP {
public: 
	typedef const T reType;
};

void f() { 
	std::cout << "global f()\n"; 
}

template<typename T>
class Base {
public:
	template <int N = 99>
	void f() { 
		std::cout << "member f(): " << N << '\n'; 
	}
};

template<typename T>
class Derived : public Base<T> {
public:
	typename T::reType m; // typename ����ʡ��
	Derived(typename T::reType a) : m(a) { }
	void df1() { f(); }							 // ����ȫ�� f()�����������еĻ��� f()
	//void df2() { this->template f(); }		 // ���� f<99>(),VS�޷�ͨ����g++˳��ͨ��
	void df2() { Base<T>::template f(); }		 // ���� f<99>()
	void df3() { Base<T>::template f<22>(); }	 // ǿ�ƻ��� f<22>()
	void df4() { ::f(); }						 // ǿ��ȫ�� f()
};

int main() {
	Derived<aTMP<int>> a(10);
	a.df1(); 
	a.df2(); 
	a.df3(); 
	a.df4();
	
	return 0;
}