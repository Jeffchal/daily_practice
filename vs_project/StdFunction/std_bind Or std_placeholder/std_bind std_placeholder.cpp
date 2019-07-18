//#include <functional>
//#include <iostream>
//
//int foo(int a, int b, int c) {
//	return a+b+c;                        
//										 
//}
//int main() {
//	// ������1,2�󶨵����� foo �ϣ�����ʹ�� std::placeholders::_1 ���Ե�һ����������ռλ
//	auto bindFoo = std::bind(foo, std::placeholders::_1, 1, 2);
//	// ��ʱ���� bindFoo ʱ��ֻ��Ҫ�ṩ��һ����������
//	std::cout<< bindFoo(3) <<std::endl;					//�����6  //a=3,b=1,c=2
//	std::cout << bindFoo(4,5) << std::endl;				//�����7  //a=4,b=1,c=2
//	
//	auto bindFoo_1 = std::bind(foo, std::placeholders::_1, 6, std::placeholders::_2);
//	std::cout << bindFoo_1(7,8) << std::endl;			//�����21  //a=7,b=6,b=8	
//
//}

#include <functional>
#include <string>
#include <iostream>

struct Polly
{
	template<typename T, typename U>
	auto operator()(T t, U u) const -> decltype(t + u)
	{
		return t + u;
	}
};

int main()
{
	auto polly = std::bind(Polly(), std::placeholders::_1, 12);
	std::cout << polly(13) << std::endl;							// �����25

	auto polly_1 = std::bind(Polly(), std::placeholders::_1, "confusing");
	std::cout << polly_1(std::string(" this is ")) << std::endl;	// �����this is confusing

	auto polly_2 = [p = Polly{}](auto t) { return p(t, 12); };
	std::cout  << polly_2(13) << std::endl;							// �����25

	auto polly_3 = [p = Polly{}](auto t) { return p(t, "confusing"); };
	std::cout << polly_3(std::string(" this is ")) << std::endl;	// �����this is confusing
	
	return 0;
}