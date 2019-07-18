//#define LEN 10
//
//constexpr int len_foo() {
////int len_foo() {
//	return 5;
//}
//
////�����岻���������������µ�����,ֻ�ܰ���������null������һ��return���
//constexpr int fibonacci(const int n) {
//	return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
//}
//
////c++14��ʼ����constexpr���εĺ�������������֧���,ѭ�����
////���ʽ���Ըı�һ�������ֵ��ֻ��ö����������������Ϊconstexpr�ĺ����ڲ���ʼ��
////constexpr int fibonacci(const int n) {
////	if (n == 1) return 1;
////	if (n == 2) return 1;
////	int result = 1;
////	for (int i = 1; i <= n; ++i)
////		result *= i;
////	return result;
////}
//
//int main() {
//	char arr_1[10];
//	char arr_2[LEN];
//	//int len = 5;
//	//char arr_3[len + 5];          // �Ƿ�
//	const int len_2 = 10;
//	char arr_4[len_2 + 5];        // �Ϸ�
//	char arr_5[len_foo() + 5];  // �Ƿ� ��int len_foo()ǰ�����constexpr ��Ϸ���
//	char arr_6[fibonacci(5)];
//
//	return 0;
//}

#include <iostream>
using namespace std;

// C++98/03
template<int N> struct Factorial_Cpp03
{
	const static int value = N * Factorial_Cpp03<N - 1>::value;
};
template<> struct Factorial_Cpp03<0>
{
	const static int value = 1;
};

// C++11
constexpr int factorial_Cpp11(int n)
{
	return n == 0 ? 1 : n * factorial_Cpp11(n - 1);
}

// C++14
constexpr int factorial_Cpp14(int n)
{
	int result = 1;
	for (int i = 1; i <= n; ++i)
		result *= i;
	return result;
}

/*
static_assert(�������ʽ����ʾ�ַ���)��
�����һ�������������ʽ��ֵΪ��(true���߷���ֵ)����ôstatic_assert�����κ����飬������������һ����
��������һ��������󣬴���λ�þ��Ǹ�static_assert��������У�������ʾ���ǵڶ���������ʾ�ַ�����
*/
int main()
{
	static_assert(Factorial_Cpp03<3>::value == 6, "error_Factorial_Cpp03");
	static_assert(factorial_Cpp11(3) == 6, "error_factorial_Cpp11");
	static_assert(factorial_Cpp14(3) == 6, "error_factorial_Cpp14");
	return 0;
}