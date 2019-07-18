// file: a.cpp
#include <iostream>

template<typename T>
class MyClass { 

};

template MyClass<double>::MyClass(); // ��ʾʵ�������캯�� MyClass<double>::MyClass()

template class MyClass<long>;        // ��ʾʵ���������� MyClass<long>

template<typename T>
void print(T const& m) {
	std::cout << "a.cpp: " << m << '\n'; 
}

void fa() {
	print(1);   // print<int>����ʽʵ����
	print(0.1); // print<double>
}

void fb(); // fb() �� b.cpp �ж��壬�˴�����

int main() {
	fa();
	fb();

	return 0;
}