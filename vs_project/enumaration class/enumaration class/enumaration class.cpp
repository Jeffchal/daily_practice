//#include <iostream>

//struct stc {
//	int a = 10;
//};
//
//int main()
//{
//	stc aa;
//	std::cout << aa.a << std::endl;
//
//}

//ʾ��1
#include <iostream>

//ö�����ͺ���ʹ����ð�ż����͹ؼ�����ָ��ö����ö��ֵ�����ͣ���ʹ�������ܹ�Ϊö�ٸ�ֵ��δָ��ʱ��Ĭ��ʹ�� int��
enum class new_enum : unsigned int {
	value1,
	value2 = 100,
	value3 = 200,
	value4 = 200
};

//ͨ�÷���
//template<typename T>
//std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
//{
//	return stream << static_cast<typename std::underlying_type<T>::type>(e);
//}

//�Լ�д�����ط���
std::ostream& operator<<(std::ostream& os, new_enum al)
{
	return os << static_cast<unsigned int>(al);
}

int main()
{
	//��ͬö��ֵ֮�����ָ����ֵ��ͬ����ô���Խ��бȽ�
	if (new_enum::value3 == new_enum::value4) {
		std::cout << "new_enum::value3 == new_enum::value4" << std::endl;
	}
	
	//������ϣ�����ö��ֵ��ֵʱ����������ʽ�Ľ�������ת�����������ǿ���ͨ������ << ���������������
	//std::cout << new_enum::value3 << std::endl;

	new_enum n_enum;
	n_enum = new_enum::value2;
	std::cout << n_enum<< std::endl;
	
	return 0;
}

//ʾ��2
//#include <iostream>
//
//// ���� 16 λ�� enum
//enum smallenum : int16_t
//{
//	a,
//	b,
//	c
//};
//
//
//// color ��Ϊ red��ֵ 0����yellow��ֵ 1����green��ֵ 20���� blue��ֵ 21��
//enum color
//{
//	red,
//	yellow,
//	green = 20,
//	blue
//};
//
//// altitude ��Ϊ altitude::high �� altitude::low
//enum class altitude : char
//{
//	high = 'h',
//	low = 'l', // C++11 ����β�涺��
//};
//
//// ���� d Ϊ 0������ e Ϊ 1������ f Ϊ 3
//enum
//{
//	d,
//	e,
//	f = e + 2
//};
//
//// ö�����ͣ��������������������ӵ�����ص������
//std::ostream& operator<<(std::ostream& os, color c)
//{
//	switch (c)
//	{
//	case red: os << "red";    break;
//	case yellow: os << "yellow"; break;
//	case green: os << "green";  break;
//	case blue: os << "blue";   break;
//	default: os.setstate(std::ios_base::failbit);
//	}
//	return os;
//}
//
//std::ostream& operator<<(std::ostream& os, altitude al)
//{
//	return os << static_cast<char>(al);
//}
//
//int main()
//{
//	color col = red;
//	altitude a;
//	a = altitude::low;
//
//	std::cout << "col = " << col << '\n'
//		<< "a = " << a << '\n'
//		<< "f = " << f << '\n';
//}
