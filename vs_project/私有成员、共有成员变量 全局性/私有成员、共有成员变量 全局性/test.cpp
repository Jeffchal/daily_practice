#include "test.h"

test::test()
{
	std::cout << "���캯����"<< a << " " << b << std::endl;
}


test::~test()
{
	a++; b++;
	std::cout << "����������" << a << " " << b << std::endl;
}

int test::add()
{
	a++; 
	std::cout << "add��"<< a << " " << b << std::endl;
	return a;
}

void test::add_2()
{
	std::cout << "add_2��" << add() << std::endl;
}
