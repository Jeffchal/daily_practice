#include <iostream>

// ʶ�����������Ƿ���ͬ����ǰ����ģ��Ԫ���^_^
template<typename T1, typename T2> // ͨ�������� false
class theSameType { 
public: 
	enum { ret = false }; 
};

template<typename T>               // ��������������ͬʱ���� true
class theSameType<T, T> { 
public: 
	enum { ret = true }; 
};

template<typename T, int i> 
class aTMP {

};

int main() {
	typedef unsigned int uint; // typedef �������ͱ�������������������
	typedef uint uint2;
	std::cout << theSameType<unsigned, uint2>::ret << '\n';
	std::cout << theSameType<aTMP<unsigned, 2>, aTMP<uint2, 2>>::ret << '\n';
	std::cout << theSameType<aTMP<int, 2>, aTMP<int, 3>>::ret << '\n';
	
	return 0;
}
