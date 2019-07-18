//#include <iostream>
//using namespace std;
//
//int g = 0;
//template<typename T>
//int foo()
//{
//	int value = ++g;
//	return value;
//}
//
//int main()
//{
//	//Qs1
//	int a = 1;
//	//cout << a << " " << ++a << " " << a++ << endl;		//��� 3 3 1 
//	cout << a << " " << a++ << " " << ++a << endl;			//��� 3 2 3  �ȼ���õ�a=3 
//
//	//Qs2
//	int one = 1;
//	//int *b = &one;
//	int *b = new int(one);
//	cout << *b << " " << ++(*b) << " " << (*b)++ << endl;		//��� 3 3 1 
//	delete b;
//	//cout << *b << " " << (*b)++  << " " << ++(*b) << endl;	//��� 3 2 3
//
//	//Qs3
//	cout << foo<int>() << " " << foo<char>() << " " << foo<float>() << " " << foo<double>() << endl;
//
//	return 0;
//}

#include <iostream>
#include <string>
#include <memory>

void foo(std::shared_ptr<int> i)
{
	(*i)++;
}
int main()
{
	// ������һ�� std::shared_ptr
	//std::shared_ptr<int> pointer(new int);
	//*pointer = 10;

	//ʹ�� std::shared_ptr ��Ȼ��Ҫʹ�� new �����ã���ʹ�ô��������ĳ�̶ֳ��ϵĲ��Գ�
	//std::make_shared ���ܹ�����������ʾ��ʹ�� new������std::make_shared ����䴴����������еĶ���
	//����������������͵�std::shared_ptrָ�롣
	auto pointer = std::make_shared<int>(10);
	foo(pointer);
	std::cout << *pointer << std::endl; 

	auto pointer1 = std::make_shared<int>(10);
	auto pointer2 = pointer1;			 // ���ü���+1
	auto pointer3 = pointer1;			 // ���ü���+1
	int *p = pointer1.get();             // ���������������ü���

	std::cout << "pointer1.use_count() = " << pointer1.use_count() << std::endl;    // 3
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;    // 3
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;    // 3

	pointer2.reset();	//ͨ�� reset() ������ָ��,��ͨ��use_count()���鿴һ����������ü�����
	std::cout << "reset pointer2:" << std::endl;
	std::cout << "pointer1.use_count() = " << pointer1.use_count() << std::endl;     // 2
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;     // 0, pointer2 �� reset
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;     // 2

	pointer3.reset();
	std::cout << "reset pointer3:" << std::endl;
	std::cout << "pointer1.use_count() = " << pointer1.use_count() << std::endl;     // 1
	std::cout << "pointer2.use_count() = " << pointer2.use_count() << std::endl;     // 0
	std::cout << "pointer3.use_count() = " << pointer3.use_count() << std::endl;     // 0, pointer3 �� reset

	// �뿪������ǰ��shared_ptr �ᱻ�������Ӷ��ͷ��ڴ�
	return 0;
}



