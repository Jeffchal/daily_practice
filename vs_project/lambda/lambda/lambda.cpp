//ֵ�������ò���
#include <iostream>
using namespace std;

void learn_lambda_func_3() {
	auto add = [v1 = 1.2, v2 = 2](int x, int y) -> double {
		return x + y + v1 + v2;
	};
	std::cout << "add(3, 4) = " << add(3, 4) << std::endl;
}

int main()
{
	learn_lambda_func_3();

	return 0;
}


//#include <iostream>
//using namespace std;
//
//void learn_lambda_func_1() {
//	int value_1 = 1;
//	auto copy_value_1 = [value_1] {
//		return value_1;
//	};
//	value_1 = 100;
//	auto stored_value_1 = copy_value_1();
//	// ��ʱ, stored_value_1 == 1, �� value_1 == 100.
//	// ��Ϊ copy_value_1 �ڴ���ʱ�ͱ�����һ�� value_1 �Ŀ���
//	cout << "value_1 = " << value_1 << endl;
//	cout << "stored_value_1 = " << stored_value_1 << endl;
//}
//
//void learn_lambda_func_2() {
//	int value_2 = 1;
//	auto copy_value_2 = [&value_2] {
//		return value_2;
//	};
//	value_2 = 100;
//	auto stored_value_2 = copy_value_2();
//	// ��ʱ, stored_value_2 == 100, value_1 == 100.
//	// ��Ϊ copy_value_2 �����������
//	cout << "value_2 = " << value_2 << endl;
//	cout << "stored_value_2 = " << stored_value_2 << endl;
//}
//
//int main()
//{
//	learn_lambda_func_1();
//	learn_lambda_func_2();
//
//	return 0;
//}


////[] �������κα���
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int i = 1024;
//	//auto func = []{ cout << i; };			//��
//	//auto func = []() { cout << i; };		//��
//	auto func = [](int i){ cout << i; };	//��
//	
//	//func();								//�٢�error C3493: �޷���ʽ����i������Ϊ��δָ��Ĭ�ϲ���ģʽ
//											//�٢�error C2064 : ������Ϊ���� 0 �������ĺ���
//	
//	func(i);								//�٢�error C3493: �޷���ʽ����i������Ϊ��δָ��Ĭ�ϲ���ģʽ
//											//�٢�error C2064: ������Ϊ���� 1 �������ĺ���
//}


