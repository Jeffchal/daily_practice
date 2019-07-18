//1����� vector ����Ϊ�㣬�� vector Ϊ�գ��ڲ�û��Ԫ�أ��ǾͲ���ȡ�õ�һ��Ԫ�صĵ�ַ��
//��Ϊ��ʱ��һ��Ԫ�ػ������ڡ������ʱ���� data() �������䷵��ֵΪ NULL��������������� 4 �ְ취������ֱ�ӱ�����
//���������ڵ��ó� data() �����������ʽ������׵�ַ��ʱ��Ҫע���ж� vector �Ƿ�Ϊ�գ�
//
//2����� vector �ĳ��ȱ仯�ˣ����磺��ͣ�ؽ��� push_back�����ǾͿ��ܵ���֮ǰȡ�õ��׵�ַ��Ϊ��Ч��
//���ԣ�Ϊ�˰�ȫ��ÿ�ν��� push_back, insert, assign ֮��Ĳ���֮�󣬶���Ҫ����ȡ���׵�ַ��
//��Ϊ֮ǰȡ�õĵ�ַ�����Ѿ���Ч�ˡ�

#include <iostream>
#include <array>

using namespace std;

void foo(int *p, int len) {
	cout << *p << " " << *(p+2) << endl;
}


int main(){

	std::array<int,4> arr = { 1,2,3,4 };

// C ���ӿڴ��� , ��ȡ�׵�ַ
	// foo(arr, arr.size());           // �Ƿ�, �޷���ʽת��
	foo(&arr[0], arr.size());
	foo(arr.data(), arr.size());
	foo(&arr.at(0), arr.size());
	foo(&arr.front(), arr.size());
	foo(&*arr.begin(), arr.size());

// ʹ�� `std::sort`
	std::sort(arr.begin(), arr.end());

	return 0;
}