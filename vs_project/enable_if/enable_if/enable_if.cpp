#include <iostream>
#include <string>
#include <type_traits>

//����arithmetic���͵���η���0�����ڷ�arithmetic���ͷ���1��ͨ��arithmetic�����е���η�Ϊ��������д���
template<class T>
typename std::enable_if<std::is_arithmetic<T>::value, int>::type foo(T t) {//������������Ϊint
	std::cout << t << std::endl;
	return t;
}

template<class T>
typename std::enable_if<!std::is_arithmetic<T>::value, int>::type foo(T t) {//������������Ϊint
	std::cout << typeid(T).name() << std::endl;
	return 1;
}

int main() {
	int num = 5;
	int array[2][2] = { 2,3,4,5 };
	char character = 'A';
	std::string str = "hello";
	std::string strarr[2][2] = { "hello","world","I","miss" };

	std::cout << "int : "	  << foo(num)		 << std::endl;
	std::cout << "array : "   << foo(array)		 << std::endl;
	std::cout << "char : "	  << foo(character)	 << std::endl;
	std::cout << "string : "  << foo(str)		 << std::endl;
	std::cout << "strarr : "  << foo(strarr)	 << std::endl;

	return 0;
}