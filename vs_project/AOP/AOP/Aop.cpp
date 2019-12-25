#include <iostream>
#include <functional>

//using namespace std;

template <typename ...Args>
std::function<void(Args...)> wrapLog(std::function<void(Args...)> f) {

	return [f](Args... args) {                                            //����������f
		std::cout << "start" << std::endl;
		f(args...);
		std::cout << "finish" << std::endl;
	};
}

template <typename Function>
struct function_traits : public function_traits<decltype(&Function::operator())> {

};

//lambda ת��Ϊ std::function<void(Args...)> ��Ҫ֪�� ����������ͺͷ���ֵ���� �����������ȡ 
template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits<ReturnType(ClassType::*)(Args...) const>		 //Args...�ɱ�ģ����� ����Ϊ��֪��lambda�����뼸������
{
	//typedef ReturnType (*pointer)(Args...);
	typedef std::function<ReturnType(Args...)> function;			
};


template <typename Function>
typename function_traits<Function>::function	//����ֵ���� function_traits<Function>::function
to_function(Function& lambda)					//������to_function���������lambda
{
	return typename function_traits<Function>::function(lambda);	//��lambda����function_traits<Function>::function 
}

//functional�����ж����˸�std::plus�������plus����Ϊglobal�ģ�����ʱ��global���Ҷ���ͻ��std::plus��ͻ���������塣
//auto plus = [](int a, int b) { std::cout << a + b << std::endl; };			//error��Plus����ȷ
std::function<void(int, int)> plus = [](int a, int b) { std::cout << a + b << std::endl; };

int main(int argc, char *argv[]) {
	//���Ǽ򵥵�lambda�����а�������ļ��㣺
	//auto plus = [](int a, int b) { cout << a + b << endl; };

	//lambda�� std :: function �޷����ת��
	//auto loggedPlus = wrapLog(plus);												//test1

	//ǿ��ת����OK�����п��Ա��룬���Ǻ��ѿ�
	auto loggedPlus  = wrapLog(static_cast<std::function<void(int, int)>>(plus));   //test2
	loggedPlus(2, 3);

	//��ʱ��ѽ������
	auto loggedPluss = wrapLog(to_function(plus));			//ͨ������to_function���� �� lambda���ʽplus ת��Ϊstd::function<void(Args...)> ��ʽ
	loggedPluss(2, 3);

	return 0;
}



//#include <iostream>
//#include <functional>
//
//using namespace std;
//
//
//template <typename ...Args>
//std::function<void(Args...)> wrapLog(std::function<void(Args...)> f)
//{
//	return [f](Args... args) {
//		cout << "start" << endl;
//		f(args...);
//		cout << "finish" << endl;
//	};
//}
//
//int a = 10, b = 15;
//int add(int i, int j) {
//	return i + j;
//}
//
////auto plus = [](int a, int b) { cout << a + b << endl; };            //error Plus����ȷ
//
//std::function<double(int,int)> addPlus = [v1 = 1, v2 = 2](int x, int y) -> double{
//	return x + y + v1 + v2;
//};
//
//int main(int argc, char *argv[]) {
//	int a = 15, b = 15;
//	cout << add(a, b) << endl;
//	cout << addPlus(a, b) << endl;
//
//	auto plus = [](int a, int b) { cout << a + b << endl; };
//	//auto loggedPlus = wrapLog(plus);                                                
//	auto loggedPlus = wrapLog(static_cast<std::function<void(int, int)>>(plus));
//
//	return 0;
//}


//#include <stdio.h>
//#include <iostream>
//
//void main() {
//	char arr1[] = "abc";
//	char arr2[] = { 'a','b','c','\0' };
//	std::cout << strlen(arr1) << std::endl;
//	printf("%d\n", strlen(arr1));
//	std::cout << strlen(arr2) << std::endl;
//	printf("%d\n", strlen(arr2));
//
//	int a = 4, b = 0, c = 0;
//	b = a << 2;
//	c = a >> 2;
//	std::cout << "a= " << a << " b= " << b << " c= " << c << std::endl;
//
//}
