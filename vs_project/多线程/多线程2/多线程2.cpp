//ʵ��һ callable objects ��ʲô���ɵ��ö���
//#include <iostream>
//#include <thread>
//
//using namespace std;
//
////function object
//struct A {
//	void operator()() {
//		cout << "I`m A " << endl;
//	}
//};
//void show() {
//	cout << "I am show" << endl;
//}
//
//int main() {
//	show();
//	A a;
//	a();
//
//	thread th = thread(A());
//	th.join();
//
//}


//ʵ��� �ഫ������
#include <iostream>
#include <string>
#include <thread>

using namespace std;

//function object
class A {
public:
	void operator()(string &s);
};

void A::operator()(string &s) {                   //��������
	cout << "S is " << s << endl;
}

int main() {
	string s = "hello";
	thread th = thread( A(), std::ref(s) );
	th.join();

}