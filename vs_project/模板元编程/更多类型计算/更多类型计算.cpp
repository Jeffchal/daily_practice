//#include <iostream> // std::cout
//
//// whether T could be converted to U
//template<class T, class U>
//class ConversionTo {
//	typedef char Type1[1]; // ���� sizeof ��ͬ������
//	typedef char Type2[2];
//	static Type1& Test(U); // ������ĺ�������Ϊ����ȡֵ��ΧС������ƥ��
//	static Type2& Test(...); // �䳤��������������ƥ���κ������κ����Ͳ���
//	static T MakeT(); // �������� T����������������� T() ��Ϊ T ����û��Ĭ�Ϲ��캯��
//public:
//	enum { ret = sizeof(Test(MakeT())) == sizeof(Type1) }; // ����ת��ʱ���÷��� Type1 �� Test()
//};
//
//int main() {
//	std::cout << ConversionTo<int, double>::ret << '\n';
//	std::cout << ConversionTo<float, int*>::ret << '\n';
//	std::cout << ConversionTo<const int&, int&>::ret << '\n';
//	
//	std::cin.get();
//	return 0;
//}

#include <iostream>
#include <vector>

// thanks to Substitution failure is not an erro (SFINAE)
template<typename T>
struct has_typedef_value_type {
	typedef char Type1[1];
	typedef char Type2[2];
	template<typename C> static Type1& test(typename C::value_type*);
	template<typename> static Type2& test(...);
public:
	static const bool ret = sizeof(test<T>(0)) == sizeof(Type1); // 0 == NULL
};

struct foo {
	typedef float lalala;
};

int main() {
	std::cout << has_typedef_value_type<std::vector<int>>::ret << '\n';
	std::cout << has_typedef_value_type<foo>::ret << '\n';

	std::cin.get();
	return 0;
}