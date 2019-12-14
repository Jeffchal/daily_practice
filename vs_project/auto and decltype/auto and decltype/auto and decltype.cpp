#include <iostream>

using namespace std;

class Person
{
public:
	enum PersonType { ADULT, CHILD, SENIOR };
	void setPersonType(PersonType person_type);
	PersonType getPersonType();
private:
	PersonType _person_type;
};

//��һ����������������ûʲô��˵�ģ������ֱ��ʹ��ö������PersonType��û�κ����⣺
void Person::setPersonType(PersonType person_type)
{
	_person_type = person_type;
}

//���ǣ��ڶ����������е������ˡ���Ư���Ĵ���ȴ�޷�ͨ������
// ��������֪�� PersonType ��ʲô����Ϊ PersonType �� Person �������ʹ��
//PersonType Person::getPersonType()
//{
//	return _person_type;
//}

//Person::PersonType Person::getPersonType()
//{
//	return _person_type;
//}

auto Person::getPersonType() -> PersonType
{
	return _person_type;
}

//error a\b can`t find  
//template <typename T1, typename T2>
//decltype(a + b) compose(T1 a, T2 b) {
//	
//		return a + b;;
//}

//template <typename T1, typename T2>
//decltype(std::declval<T1>() + std::declval<T2>())
//compose(T1 a, T2 b)
//{
//	return a + b;
//}

template <typename T1, typename T2>
auto compose(T1 a, T2 b) -> decltype(a + b) {
	return a + b;
}

int main() {
	int i=0, j=10;
	cout << compose(i,j)<< endl;

	return 0;
}




