#include"array.h"

template <class T> 
Array<T>::Array(int sz) 
{														//���캯��
	 assert(sz >= 0);								//szΪ�����С��Ԫ�ظ�������Ӧ���Ǹ�
	 size = sz;										 // ��Ԫ�ظ�����ֵ������size
	 list = new T [size];							//��̬����size��T���͵�Ԫ�ؿռ�
}

template <class T> 
Array<T>::~Array()										//��������
{ 
	delete [] list; 
}

template <class T> 
Array<T>::Array(const Array<T> &a)					//���ƹ��캯��
{				 
	 size = a.size;									 //�Ӷ���xȡ�������С������ֵ����ǰ����ĳ�Ա
	 list = new T[size];							// ��̬����n��T���͵�Ԫ�ؿռ�
	 for (int i = 0; i < size; i++)					 //�Ӷ���X��������Ԫ�ص�������
	 list[i] = a.list[i];
} 

	//����"="�������������rhs��ֵ��������ʵ�ֶ���֮������帳ֵ
template <class T>
Array<T> &Array<T>::operator = (const Array<T>& rhs)
{
	 if (&rhs != this) 
	 {
														//����������������С��rhs��ͬ����ɾ������ԭ���ڴ棬Ȼ�����·���
		 if (size != rhs.size)
		 {
			 delete [] list;									 //ɾ������ԭ���ڴ�
			 size = rhs.size;									//���ñ�����������С
			 list = new T[size];								//���·���size��Ԫ�ص��ڴ�
		 }
														 //�Ӷ���X��������Ԫ�ص�������
		 for (int i = 0; i < size; i++)
			list[i] = rhs.list[i];
	 } 
	 return *this;										 //���ص�ǰ���������
}

	//�����±��������ʵ������ͨ����һ��ͨ���±����Ԫ�أ�����Խ���鹦��
template <class T>
T &Array<T>::operator[] (int n) 
{
	 assert(n >= 0 && n < size);							//����±��Ƿ�Խ��
	 return list[n];										 //�����±�Ϊn������Ԫ��
}

template <class T>
const T &Array<T>::operator[] (int n) const 
{
	assert(n >= 0 && n < size);								//����±��Ƿ�Խ��
	return list[n];	
}															//�����±�Ϊn������Ԫ��
	

	//����ָ��ת�����������Array��Ķ�����ת��ΪT���͵�ָ��
template <class T>
Array<T>::operator T * () 
{
	return list;												//���ص�ǰ������˽��������׵�ַ
} 


	// �������С�޸�Ϊsz
template <class T>
void Array<T>::resize(int sz) 
{
	 assert(sz >= 0);											//���sz�Ƿ�Ǹ�
	 if (sz == size)											 //���ָ���Ĵ�С��ԭ�д�Сһ����ʲôҲ����
		return;
	 T* newList = new T [sz];												//�����µ������ڴ�
	 int n = (sz < size) ? sz : size;												//��sz��size�н�С��һ����ֵ��n																	//��ԭ��������ǰn��Ԫ�ظ��Ƶ���������
	 for (int i = 0; i < n; i++)
		newList[i] = list[i];
	 delete[] list;																		//ɾ��ԭ����
	 list = newList;																// ʹlistָ��������
	 size = sz;													//����size
}

template <class T>
int Array<T>::getSize() const 
{
	 return size;
}
