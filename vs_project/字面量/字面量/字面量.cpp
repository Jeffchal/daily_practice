//C++11 �ṩ��ԭʼ�ַ�����������д����������һ���ַ���ǰ��ʹ�� R ����������ַ�����ͬʱ����ԭʼ�ַ���ʹ�����Ű�����

//#include <iostream>
//#include <string>
//
//int main() {
//	std::string str = "C:\\What\\The\\Fxxk";
//	std::cout << str << std::endl;
//
//	std::string str1 = "(C:\\What\\The\\Fxxk)";
//	std::cout << str1 << std::endl;
//
//	std::string str2 = R"(C:\\What\\The\\Fxxk)";
//	std::cout << str2 << std::endl;
//	return 0;
//}

//�Զ���������

#include <iostream>
#include <string>

std::string operator"" _cchar(const char *str, size_t len) {
	return std::string(str) + " is char*";
}

std::string operator"" _ulong(unsigned long long i) {
	return std::to_string(i) + " is unsinged long long";
}
std::string operator"" _ldouble(long double i) {
	return std::to_string(i) + " is long double";
}
int main() {
	auto str = "abc"_cchar;
	auto num = 1_ulong;
	auto num2 = 2.2_ldouble;
	std::cout << str << std::endl;
	std::cout << num << std::endl;
	std::cout << num2 << std::endl;
	return 0;
}