//#include <iostream>
//#include <functional>
//
////using namespace std;
//
///*
// *
// *  ʹ����������������lambdaת��Ϊ��ͬ���͵�std :: function
// *  ԭ�ĵ�ַ��http://vitiy.info/c11-functional-decomposition-easy-way-to-do-aop/
// *
//*/
//
//template <typename ...Args>
//std::function<void(Args...)> wrapLog(std::function<void(Args...)> f) {
//
//	return [f](Args... args) {                                            //����������f
//		std::cout << "start" << std::endl;
//		f(args...);
//		std::cout << "finish" << std::endl;
//	};
//}
//
//����ǰ��������������� function_traits_base �ṹ ��һ�� �ɱ����ģ��ṹ
//template <typename> struct function_traits_base;										// ͨ���� û�� ����� ���� ��ᱨ�� ��ģ��������в�����ʹ��ģ������б�
//
//template <typename Function>
//struct function_traits : public function_traits_base<decltype(&Function::operator())> {		
//																						// https://segmentfault.com/q/1010000021360347/a-1020000021365367
//};																						// ���� function_traits �ĸ�����������Ӧ�� std::function �ػ���
//
//// lambda ת��Ϊ std::function<void(Args...)> ��Ҫ֪�� ����������ͺͷ���ֵ���� �����������ȡ 
//template <typename ClassType, typename ReturnType, typename... Args>		 // https://www.cnblogs.com/qicosmos/p/4325949.html
//struct function_traits_base<ReturnType(ClassType::*)(Args...) const>		 // ������ ��Args...�ɱ�ģ����� ����Ϊ��֪��lambda�����뼸������
//{																			 
//	typedef ReturnType (*pointer)(Args...);									 // ��ʱû�����ã���ע��
//	typedef std::function<ReturnType(Args...)> function;			
//};
//
////template <typename> struct function_traits;
////
////template  <typename ClassType, typename ReturnType, typename... Args>
////struct function_traits<ReturnType(ClassType::*)(Args...) const>										//Args...�ɱ�ģ����� ����Ϊ��֪��lambda�����뼸������
////{
////	typedef std::function<ReturnType(Args...)> function;
////};
//
//template <typename Function>
//typename function_traits<Function>::function	// ����ֵ���� - function_traits<Function>::function �� ��Ϊ wrapLog �� �������� std::function<void(Args...)> 
//to_function(Function& lambda)					// ������ - to_function��������� - lambda���������� Function& = std::function<void( xx , xx )>
//{
//	return typename function_traits<Function>::function(lambda);	//��lambda����function_traits<Function>::function,��24��
//}
//
////functional�����ж����˸�std::plus�������plus����Ϊglobal�ģ�����ʱ��global���Ҷ���ͻ��std::plus��ͻ���������塣
////auto plus = [](int a, int b) { std::cout << a + b << std::endl; };			//error��Plus����ȷ
//std::function<void(int, int)> plus = [](int a, int b) { std::cout << a + b << std::endl; };
//
//int main(int argc, char *argv[]) {
//	//���Ǽ򵥵�lambda�����а�������ļ��㣺
//	//auto plus = [](int a, int b) { cout << a + b << endl; };
//
//	//lambda�� std :: function �޷����ת��
//	//auto loggedPlus = wrapLog(plus);												//test1
//
//	//ǿ��ת����OK�����п��Ա��룬���Ǻ��ѿ�
//	auto loggedPlus  = wrapLog(static_cast<std::function<void(int, int)>>(plus));   //test2
//	loggedPlus(2, 3);
//
//	//��ʱ��ѽ������
//	auto loggedPluss = wrapLog(to_function(plus));			//ͨ������to_function���� �� lambda���ʽplus ת��Ϊstd::function<void(Args...)> ��ʽ
//	loggedPluss(2, 3);
//
//	return 0;
//}






/*
*
*  ����Ϊ��������
*
*
*/


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



#include <iostream>
#include <functional>

template<typename T1, typename T2, int i, template<typename, int> class CP>
class TMP {                                           // ͨ�� �� û����� ���� ��ģ��������в�����ʹ��ģ������б�

};

template<typename T1, typename T2, int i, template<typename, int> class CP>
struct TMP<const T1, T2, i, CP> {                    // ������

};


template <typename> struct function_traits_base;

																			
template <typename ClassType, typename ReturnType, typename... Args>
struct function_traits_base<ReturnType(ClassType::*)(Args...) const>		
{
	typedef ReturnType (*pointer)(Args...);									
	typedef std::function<ReturnType(Args...)> function;			
};

template <typename Function>
struct function_traits : public function_traits_base<decltype(&Function::operator())> {

};	


int main() {



	return 0;
}