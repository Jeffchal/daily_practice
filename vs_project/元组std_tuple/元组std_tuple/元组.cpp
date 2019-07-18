//#include <iostream>  
//#include <tuple>
//#include <string>
//
//auto get_student(int id)
//{
//	// �������ͱ��ƶ�Ϊ std::tuple<double, char, std::string>
//
//	if (id == 0)
//		return std::make_tuple(3.8, 'A', "����");
//	if (id == 1)
//		return std::make_tuple(2.9, 'C', "����");
//	if (id == 2)
//		return std::make_tuple(1.7, 'D', "����");
//	return 
//		std::make_tuple(0.0, 'D', "null");	// ���ֻд 0 ������ƶϴ���, ����ʧ��
//}
//
//int main()
//{
//	auto student = get_student(0);
//	std::cout << "ID: 0, "
//		<< "GPA: "  << std::get<0>(student) << ", "
//		<< "�ɼ�: " << std::get<1>(student) << ", "
//		<< "����: " << std::get<2>(student) << '\n';
//
//	double gpa;
//	char grade;
//	std::string name;
//
//	// Ԫ����в��
//	std::tie(gpa, grade, name) = get_student(1);
//	std::cout << "ID: 1, "
//		<< "GPA: "  << gpa << ", "
//		<< "�ɼ�: " << grade << ", "
//		<< "����: " << name << '\n';
//
//	std::tuple<std::string, double, double, int> t("123", 4.5, 6.7, 8);
//	std::cout << std::get<std::string>(t) << std::endl;
//	//std::cout << std::get<double>(t) << std::endl;   // �Ƿ�, ���������ڴ���
//	std::cout << std::get<3>(t) << std::endl;
//
//}


// C++ code to demonstrate tuple, get() and make_pair() 
//#include<iostream> 
//#include<tuple> // for tuple 
//using namespace std;
//int main()
//{
//	// Declaring tuple 
//	tuple <char, int, float> geek;
//
//	// Assigning values to tuple using make_tuple() 
//	geek = make_tuple('a', 10, 15.5);
//
//	// Printing initial tuple values using get() 
//	cout << "The initial values of tuple are : ";
//	cout << get<0>(geek) << " " << get<1>(geek);
//	cout << " " << get<2>(geek) << endl;
//
//	// Use of get() to change values of tuple 
//	get<0>(geek) = 'b';
//	get<2>(geek) = 20.5;
//
//	// Printing modified tuple values 
//	cout << "The modified values of tuple are : ";
//	cout << get<0>(geek) << " " << get<1>(geek);
//	cout << " " << get<2>(geek) << endl;
//
//	return 0;
//}

//C++ code to demonstrate tuple_size 
#include<iostream> 
#include<tuple> // for tuple_size and tuple 
using namespace std;
int main()
{

	// Initializing tuple 
	tuple <char, int, float> geek(20, 'g', 17.5);

	// Use of size to find tuple_size of tuple 
	cout << "The size of tuple is : ";
	cout << tuple_size<decltype(geek)>::value << endl;

	return 0;

}