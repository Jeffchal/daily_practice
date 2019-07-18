//#include <iostream>
//#include <string>

/*��������ĸ���
template<typename... Args>
void magic(Args... args) {
	std::cout << sizeof...(args) << std::endl;
}
int main()
{
	magic();        // ���0
	magic(1);       // ���1
	magic(1, "");   // ���2

}
*/

/********************************************************************************/
/*******************								 ****************************/
/*##################�Բ������н��,���־���Ĵ����ַ�###########################*/
/*******************								 ****************************/
/********************************************************************************/


/********************************************************************************/
//һ���ݹ�ģ�庯��
//�ݹ�ģ�庯����һ�ֱ�׼����������ȱ���Զ��׼������ڱ��붨��һ����ֹ�ݹ�ĺ�����
//���������ÿһ��������ֱ��Ϊ��ʱ���empty��
//չ���������ĺ�����������һ���ǵݹ麯��������һ���ǵݹ���ֹ������������Args...��չ���Ĺ����еݹ�
//�����Լ���ÿ����һ�β������еĲ����ͻ���һ����ֱ�����еĲ�����չ��Ϊֹ����û�в���ʱ��
//����÷�ģ�庯��print��ֹ�ݹ���̡�
//�ݹ���õĹ�����������:
//print(1,2,3,4);
//print(2, 3, 4);
//print(3, 4);
//print(4);
//print();

//#include <iostream>
//using namespace std;
////�ݹ���ֹ����
//void print()
//{
//	cout << "empty" << endl;
//}
////չ������
//template <class T, class ...Args>
//void print(T head, Args... rest)
//{
//	cout << "parameter " << head << endl;
//	print(rest...);
//}
//
//
//int main(void)
//{
//	print(1, 2, 3, 4);
//	return 0;
//}


/**************************************************************************************************/
//����ĵݹ���ֹ����������д������
//�޸ĵݹ���ֹ�����������еĵ��ù�����������
//print(1, 2, 3, 4);
//print(2, 3, 4);
//print(3, 4);
//print(4);

//#include <iostream>
//
//template<typename T>
//void printf(T value) {
//	std::cout << value << std::endl;
//}
//
//template<typename T, typename... Args>
//void printf(T value, Args... args) {        //�ú���������0������
//	std::cout << value << std::endl;
//	printf(args...);                        //����printf(T value, Args... args)����������ʣ��һ��������printf(T value) 
//}
//
//
//int main() {
//	printf(1, 2, "123", 1.1);		//�ݹ�ģ�庯��
//	return 0;
//}



/******************************************************************************************************/
//������ʹ�õݹ�汾���������ű��ʽ�ͳ�ʼ���б�

//printarg����һ���ݹ���ֹ������ֻ��һ�������������ÿһ�������ĺ�����
//���ű��ʽ�����־͵�չ���������ķ�ʽʵ�ֵĹؼ��Ƕ��ű��ʽ�����ű��ʽ�ᰴ˳��ִ�ж���ǰ��ı��ʽ��
//            ���ű��ʽ�ᰴ˳��ִ�ж���ǰ��ı��ʽ�����磺d = (a = b, a+c); 
//            ������ʽ�ᰴ˳��ִ�У�b���ȸ�ֵ��a�����������еĶ��ű��ʽ����a+c��ֵ�����d������a+c��
//��ʼ���б�ͨ����ʼ���б�����ʼ��һ���䳤����, { (printarg(args), 0)... }����չ����
//            ((printarg(arg1), 0), (printarg(arg2), 0), (printarg(arg3), 0), etc...)��
//            ���ջᴴ��һ��Ԫ��ֵ��Ϊ0������int arr[sizeof...(Args)]��

//#include <iostream>
//
//template <class T>
//void printarg(T t)
//{
//	std::cout << t << std::endl;
//}
//
//template <class ...Args>
//void expand(Args... args)
//{
//	int arr[] = { (printarg(args), 0)... };
//}
//
//int main() {
//	expand(1, 2, 3, 4);
//
//	return 0;
//}


//���ǿ��԰�����������ٽ�һ���Ľ�һ�£���������Ϊ�������Ϳ���֧��lambda���ʽ�ˣ�
//�Ӷ�������дһ���ݹ���ֹ�����ˣ�����������£�


//#include <iostream>
//
//template<class F, class... Args>void expand(const F& f, Args&&...args)
//{
//	//�����õ�������ת��
//	std::initializer_list<int>{(f(std::forward<Args>(args)), 0)...};
//}
//
//int main() {
//	expand([](int i) {std::cout << i << std::endl; }, 1, 2, 3);
//	//expand([](auto i) {std::cout << i << std::endl; }, 1, 2.0, ��test��);
//
//	return 0;
//}


//ͨ����ʼ���б�(lambda ���ʽ, value)... ���ᱻչ����
//���ڶ��ű��ʽ�ĳ��֣����Ȼ�ִ��ǰ��� lambda ���ʽ����ɲ����������
//Ψһ�����۵ĵط����������ʹ�� return �����������δʹ�õı�����Ϊ���档
//C++14�������Է���lambda���ʽ.��������lambda���ʽ,����auto.
//�������������Ҫ���� -std=c++14

////lambda���ʽ������[](){}������������[](){}(). 
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	[](){
//		cout << "Hello,World\n";
//	}();
//}

#include <iostream>

template<typename T, typename... Args>
auto print(T value, Args... args) {
	std::cout << value << std::endl;
	return std::initializer_list<T>{([&](){
		std::cout << args << std::endl;
	}(), value)...};
}
int main() {
	print(1, 2.1, "test");			//ʹ�ó�ʼ���б�
	return 0;
}

