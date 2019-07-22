#include <iostream>

// ͨ��Ϊ�գ�����ƥ�������������ܺõĵ����ֶΣ������� bool ������ν�ˣ�
template<bool c, typename Then, typename Else> 
class IF_ { 

};

template<typename Then, typename Else>
class IF_<true, Then, Else> {
public: 
	typedef Then reType; 
};

template<typename Then, typename Else>
class IF_<false, Then, Else> {
public:
	typedef Else reType; 
};

// ����Ҫ�� Condition ����ֵ ret��Statement ������ Next
template<template<typename> class Condition, typename Statement>
class WHILE_ {
	template<typename Statement>
	class STOP {
	public: 
		typedef Statement reType;
	};
public:
	typedef typename IF_<Condition<Statement>::ret,WHILE_<Condition, typename Statement::Next>,STOP<Statement>>::reType::reType reType;
};


int main() {
	const int len = 4;
	typedef	IF_<sizeof(short) == len, short,
				IF_<sizeof(int) == len, int,
					IF_<sizeof(long) == len, long,
						IF_<sizeof(long long) == len, long long,
						void>
					::reType>
				::reType>
			::reType>::reType int_my; // ����һ��ָ���ֽ���������
		std::cout << sizeof(int_my) << '\n';
		
		std::cin.get();
		return 0;
}


//// ���� 1^e+2^e+...+n^e
//template<int n, int e>
//class sum_pow {
//	template<int i, int e> 
//	class pow_e {
//	public:
//		enum { ret = i * pow_e<i, e - 1>::ret };
//	};
//
//	template<int i> class pow_e<i, 0> { 
//	public:
//		enum { ret = 1 };
//	};
//
//	// ���� i^e��Ƕ����ʹ���ܹ�����Ƕ��ģ��Ԫ������private ���ʿ�������ʵ��ϸ��
//	template<int i> class pow {
//	public:
//		enum { ret = pow_e<i, e>::ret };
//	};
//
//	template<typename stat>
//	class cond { 
//	public: 
//		enum { ret = (stat::ri <= n) };
//	};
//
//	template<int i, int sum>
//	class stat {
//		public: 
//			typedef stat<i + 1, sum + pow<i>::ret> Next;
//			enum { ri = i, ret = sum };
//	};
//
//public:
//	enum { ret = WHILE_<cond, stat<1, 0>>::reType::ret };
//};
//
//int main() {
//	std::cout << sum_pow<10, 2>::ret << '\n';
//
//	std::cin.get();
//	return 0;
}