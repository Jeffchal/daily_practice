#include <iostream>
#include <vector>
#include <array>
using namespace std;

int main()
{
	int len = 4;
	//std::array<int, len> arr = { 1,2,3,4 };
	std::array<int,4> arr = { 1,2,3,4 };

	return 0;
}

//#include <string>
//#include <iterator>
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int main()
//{
//	// �þۺϳ�ʼ������
//	std::array<int, 3> a1{ {1, 2, 3} }; // CWG 1270 ����ǰ�� C++11 ��Ҫ��˫������
//										// �� C++11 ֮��İ汾�� C++14 ��Ҫ��
//	std::array<int, 3> a2 = { 1, 2, 3 };  // = �����Ҫ��
//	std::array<std::string, 2> a3 = { std::string("a"), "b" };
//
//	// ֧����������
//	std::sort(a1.begin(), a1.end());
//	std::reverse_copy(a2.begin(), a2.end(),
//		std::ostream_iterator<int>(std::cout, " "));
//
//	std::cout << '\n';
//
//	// ֧�ִ���Χ for ѭ��
//	for (const auto& s : a3)
//		std::cout << s << ' ';
//}