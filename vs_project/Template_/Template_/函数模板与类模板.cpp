#include <iostream>

// ����ģ��
template<typename T>
bool equivalent(const T& a, const T& b) {
	return !(a < b) && !(b < a);
}

// ��ģ��
template<typename T = int> // Ĭ�ϲ���
class bignumber {
	T _v;
public:
	bignumber(T a) : _v(a) { }
	inline bool operator<(const bignumber& b) const; // �ȼ��� (const bignumber<T>& b)
};

// ����ģ����ʵ�ֳ�Ա����
template<typename T>
bool bignumber<T>::operator<(const bignumber& b) const {
	return _v < b._v;
}

int main()
{
	bignumber<> a(1), b(1); // ʹ��Ĭ�ϲ�����"<>"����ʡ��
	std::cout << equivalent(a, b) << '\n'; // ����ģ������Զ��Ƶ�
	std::cout << equivalent<double>(1, 2) << '\n';
    
	return 0;
}