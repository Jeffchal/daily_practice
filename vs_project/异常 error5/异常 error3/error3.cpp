//noexcept https://www.shiyanlou.com/courses/

//#include <iostream>
//
//void may_throw() {
//	throw true;
//}
//auto non_block_throw = [] {
//	may_throw();
//};
//void no_throw() {	//noexcept {
//		return;
//}
//auto block_throw = [](){	// noexcept {
//	no_throw();
//};
//
//int main()
//{
//	//noexcept �������������������ڲ���һ�����ʽ�������ʽ���쳣ʱ������ true�����򷵻� false��
//	std::cout << std::boolalpha
//			  << "may_throw() noexcept? "	<< noexcept(may_throw())		 << std::endl
//			  << "lmay_throw() noexcept? "	<< noexcept(non_block_throw())	 << std::endl
//			  << "no_throw() noexcept? "	<< noexcept(no_throw())			 << std::endl
//			  << "lno_throw() noexcept? "	<< noexcept(block_throw())		 << std::endl;
//	
//	try {
//		may_throw();
//	}
//	catch (...) {
//		std::cout << "�����쳣, ���� my_throw()" << std::endl;
//	}
//	try {
//		non_block_throw();
//	}
//	catch (...) {
//		std::cout << "�����쳣, ���� non_block_throw()" << std::endl;
//	}
//	try {
//		block_throw();
//	}
//	catch (...) {
//		std::cout << "�����쳣, ���� block_throw()" << std::endl;
//	}
//
//	return 0;
//}

// error3.cpp -- using an exception

//#include <iostream>
//double hmean(double a, double b);
//
//int main()
//{
//	double x, y, z;
//
//	std::cout << "Enter two numbers: ";
//	while (std::cin >> x >> y)
//	{
//		try {                   // start of try block
//			z = hmean(x, y);
//		}                       // end of try block
//		catch (const char * s)  // start of exception handler
//		{
//			std::cout << s << std::endl;
//			std::cout << "Enter a new pair of numbers: ";
//			continue;
//		}                       // end of handler
//		std::cout << "Harmonic mean of " << x << " and " << y
//			<< " is " << z << std::endl;
//		std::cout << "Enter next set of numbers <q to quit>: ";
//	}
//	std::cout << "Bye!\n";
//	return 0;
//}
//
//double hmean(double a, double b)
//{
//	if (a == -b)
//		throw "bad hmean() arguments: a = -b not allowed";
//	return 2.0 * a * b / (a + b);
//}
