//std::shared_ptr �ͻᷢ����Ȼ��������Դ�޷��ͷŵ�����

//#include <iostream>
//#include <memory>
//
//class A;
//class B;
//
//class A {
//public:
//	std::shared_ptr<B> pointer;
//	~A() {
//		std::cout << "A ������" << std::endl;
//	}
//};
//class B {
//public:
//	std::shared_ptr<A> pointer;
//	~B() {
//		std::cout << "B ������" << std::endl;
//	}
//};
//int main() {
//	std::shared_ptr<A> a = std::make_shared<A>();
//	std::shared_ptr<B> b = std::make_shared<B>();
//	a->pointer = b;
//	b->pointer = a;
//
//	return 0;
//}




//����������İ취����ʹ��������ָ�� std::weak_ptr��std::weak_ptr��һ�������ã���Ƚ϶��� std::shared_ptr ����һ��ǿ���ã�
//�����ò����������ü�������.
//std::weak_ptr û�� * ������� -> ����������Բ��ܹ�����Դ���в���������Ψһ���þ������ڼ�� std::shared_ptr �Ƿ���ڣ�
//expired() ��������Դδ���ͷ�ʱ���᷵�� true�����򷵻� false��
#include <iostream>
#include <memory>

class A;
class B;

class A {
public:
	// A �� B ��������һ��ʹ�� weak_ptr
	std::weak_ptr<B> pointer;
	~A() {
		std::cout << "A ������" << std::endl;
	}
};
class B {
public:
	std::shared_ptr<A> pointer;
	~B() {
		std::cout << "B ������" << std::endl;
	}
};
int main() {
	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<B> b = std::make_shared<B>();
	a->pointer = b;
	b->pointer = a;

	return 0;
}

//shared_ptr �� weak_ptr ��һ��ǿ���ú������õĹ�ϵ��
//һ��ǿ���õ������õĶ�����ŵĻ����������Ҳ���ڣ�����˵����������һ��ǿ���ã���ô�������Ͳ��ܱ��ͷţ���
//��Զ��ԣ������õ����õĶ�����ŵ�ʱ��һ������, �����ǵ������ڵ�ʱ���һ�����á�
//�����ò����޸ĸö�������ü���������ζ���������������Զ�����ڴ���й����ڹ�������������ָͨ��.һ���Ƚϴ�������ǣ�
//�������ܼ�⵽������Ķ����Ƿ��Ѿ����ͷţ��Ӷ�������ʷǷ��ڴ档