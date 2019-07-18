//���̵߳ĺô���https://blog.csdn.net/shfqbluestone/article/details/45825269


////ʵ��һ ��˫�߳����
//#include <iostream>
//#include <thread>
//
//using namespace std;
//
//void func() {
//	cout << "hello,this is my thread ��thread id is " 
//	<<this_thread::get_id()	<< endl;
//}
//
//int main() {
//	cout << "this is main thread ��thread id is " << this_thread::get_id() << endl;
//	
//	thread th = thread(func);       //�����̣߳����뺯��ָ��
//	th.join();		//����/��ϣ�˵���˾����������������̣߳������̵߳ȴ����߳�ִ����ϣ����̺߳����̻߳�ϣ�Ȼ�����߳��������ߣ�
//	//th.detach();  //���룬Ҳ�������̲߳������̻߳���ˣ������߳�ִ����ģ������߳�ִ���ҵģ������߳�Ҳ���ص������߳����н��������߳̿�����ִ�н������Ⲣ��Ӱ�����̵߳�ִ�С�
//}

//ʵ��� ��������������߳����,��������
//#include <iostream>
//#include <string>
//#include <thread>
//
//using namespace std;
//
//void func(string& s) {
//	cout << "hello,this is my thread ��thread id is "
//		<< s << endl;
//}
//
//int main() {
//	string s = "test";
//	thread th = thread( func,std::ref(s));       //���뺯��ָ�룬����Ӻ���������������ref()��
//	th.join(); 
//	cout << "this is main thread ��thread id is "
//		<< this_thread::get_id() << endl;
//	//th.detach();
//}

//ʵ������
#include <iostream>
#include <thread>

using namespace std;

//auto fn = [](int *a) {
//	for (int i = 0; i < 10; i++)
//		cout << *a << endl;
//};
//
//int main() {
//	
//	[] {
//		int a = 100;
//		thread t(fn, &a);
//		t.detach();
//	}();
//	
//	
//
//	return 0;
//}


class thread_guard
{
private:
	thread &t;
public:
	explicit thread_guard(thread& _t) :
		t(_t) {}

	~thread_guard()
	{
		if (t.joinable())
			t.join();
	}

	thread_guard(const thread_guard&) = delete;
	thread_guard& operator=(const thread_guard&) = delete;
};

void func() {

	thread t([] {
		cout << "Hello thread" << endl;
	});

	thread_guard g(t);
}
void func1() {
	thread t([] {
		cout << "hello C++ 11" << endl;
	});

	try
	{
		;
	}
	catch (...)
	{
		t.join();
		throw;
	}
	t.join();
}
int main() {
	
	//func();
	func1();

	return 0;
}



