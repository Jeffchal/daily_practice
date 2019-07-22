#include <iostream>


// Prime number computation by Erwin Unruh
template<int i> struct D { D(void*); operator int(); }; // ���캯������Ϊ void* ָ��

template<int p, int i> struct is_prime { // �ж� p �Ƿ�Ϊ�������� p �������� 2...p-1
	enum { prim = (p%i) && is_prime<(i > 2 ? p : 0), i - 1>::prim };
};
template<> struct is_prime<0, 0> { enum { prim = 1 }; };
template<> struct is_prime<0, 1> { enum { prim = 1 }; };

template<int i> struct Prime_print {
	Prime_print<i - 1> a;
	enum { prim = is_prime<i, i - 1>::prim };
	// prim Ϊ��ʱ�� prim?1:0 Ϊ 1��int �� D<i> ת��������ʱ�� 0 Ϊ NULL ָ�벻����
	void f() { D<i> d = prim ? 1 : 0; a.f(); } // ���� a.f() ʵ���� Prime_print<i-1>::f()
};
template<> struct Prime_print<2> { // �������ݹ���ֹ
	enum { prim = 1 };
	void f() { D<2> d = prim ? 1 : 0; }
};

#ifndef LAST
#define LAST 10
#endif

int main() {
	Prime_print<LAST> a; a.f(); // ������� a.f() ��ʵ���� Prime_print<LAST>::f()
}