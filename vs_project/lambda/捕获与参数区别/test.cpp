#include <functional>
#include <iostream> 

std::function<int(int)> make_adder(int add_by) { 
	return [=](int ival) { return ival + add_by; };  //û�в���=��������
} 
std::function<int(int,int)> make_adder_1(int add_by) {
	return [](int ival, int add_by) { return ival + add_by; };   // make_adder_1 �Ĳ����� add_by_14 �޹�
}

int main() {
	auto add_by_12 = make_adder(12); 
	std::cout << add_by_12(30) << std::endl; 

	int b = 40;
	std::cout << add_by_12(b) << std::endl;

	auto add_by_14 = make_adder_1(60);
	std::cout << add_by_14(30,20) << std::endl;

	return 0;
}
