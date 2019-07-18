//ʵ��һ��δ����ʵ��ֵС��ʵ��ֵ400W ����Ϊ��Ϊ�ĸ��߳�S++��ͨ�����ô��룬�����߳�1���߳�2��          S++�ص���
//#include <iostream>
//#include <thread>
//#include <future>
//#include <vector>
//
//using namespace std;
//
//template<class T>
//void measure(T&& func) {
//	using namespace std::chrono;
//	auto start = system_clock::now();
//	func();
//	duration<double> diff = system_clock::now() - start;
//	cout << "elapsed: " << diff.count() << "second" << endl;
//
//}
//
//// [a,b)
//void sum(int &s) {
//	for (long i = 0; i < 1000000; i++) {
//		s++;
//	}
//}
//
//const long S = 100000000;
//
//int main() {
//
//	measure([]() {
//		vector<thread> v;
//		int s = 0;
//		for (int i = 0; i < 4; i++) {
//			v.emplace_back(sum, std::ref(s));
//		}
//		for (int i = 0; i < 4; i++) {
//			v[i].join();
//		}
//		cout << s << endl;
//	});
//
//
//	return 0;
//}

//ʵ�������ӻ����� �õ�ʵ��ֵ400w
#include <iostream>
#include <thread>
#include <future>
#include <vector>

using namespace std;

template<class T>
void measure(T&& func) {
	using namespace std::chrono;
	auto start = system_clock::now();
	func();
	duration<double> diff = system_clock::now() - start;
	cout << "elapsed: " << diff.count() << "second" << endl;

}

std::mutex mtx;
// [a,b)
void sum(int &s) {
	mtx.lock();
	for (long i = 0; i < 1000000; i++) {
		s++;
	}
	mtx.unlock();
}

const long S = 100000000;

int main() {

	measure([]() {
		vector<thread> v;
		int s = 0;
		for (int i = 0; i < 4; i++) {
			v.emplace_back(sum, std::ref(s));
		}
		for (int i = 0; i < 4; i++) {
			v[i].join();
		}
		cout << s << endl;
	});


	return 0;
}