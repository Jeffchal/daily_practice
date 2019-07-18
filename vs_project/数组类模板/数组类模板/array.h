#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
template <class T> //������ģ�嶨��
class Array {
private:
	T* list; //���ڴ�Ŷ�̬����������ڴ��׵�ַ
	int size; //�����С��Ԫ�ظ�����
public:
	Array(int sz = 50); //���캯��
	Array(const Array<T> &a); //���ƹ��캯��
	~Array(); //��������
	Array<T> & operator = (const Array<T> &rhs); //����"=��
	 T & operator [] (int i); //����"[]��
	 const T & operator [] (int i) const; //����"[]��������
	operator T * (); //���ص�T*���͵�ת��
	//operator const T * () const;
	int getSize() const; //ȡ����Ĵ�С
	void resize(int sz); //�޸�����Ĵ�С
}; 

#endif