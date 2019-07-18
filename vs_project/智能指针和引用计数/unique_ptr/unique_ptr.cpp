#include <iostream>
#include <string>
#include <memory>

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique(Args&& ...args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

struct Foo {
	Foo() { std::cout << "Foo::Foo" << std::endl; }
	~Foo() { std::cout << "Foo::~Foo" << std::endl; }
	void foo() { std::cout << "Foo::foo" << std::endl; }
};

void f(const Foo &) {
	std::cout << "f(const Foo&)" << std::endl;
}

int main()
{
	//std::unique_ptr ��һ�ֶ�ռ������ָ�룬����ֹ��������ָ�����乲��ͬһ�����󣬴Ӷ���֤�˴���İ�ȫ
	std::unique_ptr<int> pointer = std::make_unique<int>(10);	 // make_unique �� C++14 ����
	//std::unique_ptr<int> pointer2 = pointer;    // �Ƿ�

	std::unique_ptr<Foo> p1(std::make_unique<Foo>());       //���:Foo::Foo
	// p1 ����, ���
	if (p1) p1->foo();										//���:Foo::foo
	{
		//��Ȼ�Ƕ�ռ�����仰˵���ǲ��ɸ��ơ����ǣ����ǿ������� std::move ����ת�Ƹ������� unique_ptr
		std::unique_ptr<Foo> p2(std::move(p1));

		// p2 ����, ���
		f(*p2);												//���:f(const Foo&)

		// p2 ����, ���
		if (p2) p2->foo();									//���:Foo::foo

		// p1 Ϊ��, �����
		if (p1) p1->foo();									
		
		//��p2����Ȩ����p1
		p1 = std::move(p2);

		// p2 Ϊ��, �����
		if (p2) p2->foo();
		std::cout << "p2 ������" << std::endl;				//���:p2 ������
	}
	// p1 ����, ���
	if (p1) p1->foo();										//���:Foo::foo

	// Foo ��ʵ�������뿪������ʱ������

	return 0;												//���:Foo::~Foo
}
