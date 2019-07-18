//�Ƶ�ʾ��

//#include <iostream>
////using namespace std;
//
//void reference(int& v) {
//	std::cout << "��ֵ" << std::endl;
//}
//
//void reference(int&& v) {													/*������*/
//	std::cout << "��ֵ" << std::endl;										//������ֵ:
//}																			//��ͨ����:��ֵ
//
//template <typename T>														//������ֵ:
//void pass(T&& v) {														//��ͨ����:��ֵ
//	std::cout << "��ͨ����:";
//	reference(v);   // ʼ�յ��� reference(int& )
//}
//
//int main() {
//	std::cout << "������ֵ:" << std::endl;
//	pass(1);        // 1����ֵ, �������ֵ: �����ƶ���䣬����reference(v),������ v ��һ�����ã�����ͬʱҲ����ֵ��
//					// ��� reference(v) ����� reference(int&)���������ֵ����
//	std::cout << std::endl;
//	std::cout << "������ֵ:" << std::endl;
//	int v = 1;
//	pass(v);        // v��������, Ϊʲô������ƶ���䣬�����ֵ��
//					// ���ǻ�������̮������ģ��ڴ�ͳ C++ �У����ǲ��ܹ���һ���������ͼ����������ã�
//					// �� C++ ������ֵ���õĳ��ֶ��ſ�����һ�������Ӷ�����������̮�������������Ƕ����ý������ã����������ã����������á�
//
//	return 0;
//}
//ģ�庯����ʹ�� T&& ��һ���ܽ�����ֵ���ã���������ֵʱ���˺��������ý����Ƶ�Ϊ��ֵ��
//��׼ȷ�Ľ�������ģ�������ʲô���͵����ã����ҽ���ʵ������Ϊ������ʱ��ģ��������ܱ��Ƶ�Ϊ���������͡�
//���Բ�ʹ�� v ��Ϊ��ֵ�ĳɹ����ݡ�

//����ת��
//��ν����ת��������Ϊ���������ڴ��ݲ�����ʱ�򣬱���ԭ���Ĳ������ͣ������ñ��������ã������ñ��������ã���
//Ϊ�˽��������⣬����Ӧ��ʹ�� std::forward �����в�����ת�������ݣ���
#include <iostream>
#include <utility>

void reference(int& v) {
	std::cout << "��ֵ����" << std::endl;
}

void reference(int&& v) {
	std::cout << "��ֵ����" << std::endl;
}

//template <typename T>
//void pass(T& v) {
//	std::cout << "��ͨ����0:";
//	reference(v);
//	std::cout << "std::move ����0:";
//	reference(std::move(v));
//	std::cout << "std::forward ����0:";
//	reference(std::forward<T>(v));
//}

template <typename T>
void pass(T&& v) {
	std::cout << "��ͨ����:";
	reference(v);							   //�����۵�������
	std::cout << "std::move ����:";
	reference(std::move(v));                   //ǿ��ת��Ϊ��ֵ
	std::cout << "std::forward ����:";
	reference(std::forward<T>(v));             //��ʾʵ������

}

int main() {
	std::cout << "������ֵ:" << std::endl;
	pass(1);
	std::cout <<  std::endl;

	std::cout << "������ֵ:" << std::endl;
	int v = 1;
	pass(v);

	return 0;
}