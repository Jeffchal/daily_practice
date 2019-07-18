// string::find
//
//string (1)	size_t find (const string& str, size_t pos = 0) const;
//c-string (2)	size_t find (const char* s, size_t pos = 0) const;
//buffer (3)	size_t find (const char* s, size_t pos, size_t n) const;
//character (4)	size_t find (char c, size_t pos = 0) const;
//��ָ��posʱ������������λ��pos����֮����ַ������԰���pos֮ǰ���ַ����κο��ܵĳ��֡�
//��ע�⣬���Աfind_first_of��ͬ��ÿ����������ַ�ʱ����������һ���ַ�ƥ���ǲ����ģ����������б���ƥ�䡣


#include <iostream>       // std::cout
#include <string>         // std::string

int main ()
{
	std::string str ("There are two needles in this haystack with needles.");
	std::string str2 ("needle");

	// different member versions of find in the same order as above:
	std::size_t found = str.find(str2);
	if (found!=std::string::npos)
		std::cout << "first 'needle' found at: " << found << '\n';

	found=str.find("needles are small",found+1,6);
	if (found!=std::string::npos)
		std::cout << "second 'needle' found at: " << found << '\n';

	found=str.find("haystack");
	if (found!=std::string::npos)
		std::cout << "'haystack' also found at: " << found << '\n';

	found=str.find('.');
	if (found!=std::string::npos)
		std::cout << "Period found at: " << found << '\n';

	// let's replace the first needle:
	str.replace(str.find(str2),str2.length(),"preposition");
	std::cout << str << '\n';

	return 0;
}