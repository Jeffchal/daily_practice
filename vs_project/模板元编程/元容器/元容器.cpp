//#include <iostream>
//
//class null_type {}; // ��ǩ�࣬��ǲ����б�ĩβ
//template<typename T0, typename T1, typename T2, typename T3>
//class type_shift_node {
//public:
//	typedef T0 data_type;
//	typedef type_shift_node<T1, T2, T3, null_type> next_type; // ������λ��
//	static const int num = next_type::num + 1; // �� null_type ģ���������
//	data_type data; // ���ڵ�����
//	next_type next; // �������нڵ�����
//	type_shift_node() :data(), next() { } // ���캯��
//	type_shift_node(T0 const& d0, T1 const& d1, T2 const& d2, T3 const& d3)
//		:data(d0), next(d1, d2, d3, null_type()) { } // next ����Ҳ��λ��
//};
//template<typename T0> // �������ݹ���ֹ
//class type_shift_node<T0, null_type, null_type, null_type> {
//public:
//	typedef T0 data_type;
//	static const int num = 1;
//	data_type data; // ���ڵ�����
//	type_shift_node():data() { } // ���캯��
//	type_shift_node(T0 const& d0, null_type, null_type, null_type) : data(d0) { }
//};
//// Ԫ����ģ�壬Ĭ�ϲ��� + Ƕ�׵ݹ�
//template<typename T0, typename T1 = null_type, typename T2 = null_type,
//	typename T3 = null_type>
//	class my_tuple {
//	public:
//		typedef type_shift_node<T0, T1, T2, T3> tuple_type;
//		static const int num = tuple_type::num;
//		tuple_type t;
//		my_tuple(T0 const& d0 = T0(), T1 const& d1 = T1(), T2 const& d2 = T2(), T3 const& d3 = T3())
//			: t(d0, d1, d2, d3) { } // ���캯����Ĭ�ϲ���
//};
//
//// Ϊ�������Ԫ�����ݣ����� get<unsigned>(tuple) ����ģ��
//template<unsigned i, typename T0, typename T1, typename T2, typename T3>
//class type_shift_node_traits {
//public:
//	typedef typename
//		type_shift_node_traits<i - 1, T0, T1, T2, T3>::node_type::next_type node_type;
//	typedef typename node_type::data_type data_type;
//	static node_type& get_node(type_shift_node<T0, T1, T2, T3>& node)
//	{
//		return type_shift_node_traits<i - 1, T0, T1, T2, T3>::get_node(node).next;
//	}
//};
//template<typename T0, typename T1, typename T2, typename T3>
//class type_shift_node_traits<0, T0, T1, T2, T3> {
//public:
//	typedef typename type_shift_node<T0, T1, T2, T3> node_type;
//	typedef typename node_type::data_type data_type;
//	static node_type& get_node(type_shift_node<T0, T1, T2, T3>& node)
//	{
//		return node;
//	}
//};
//template<unsigned i, typename T0, typename T1, typename T2, typename T3>
//typename type_shift_node_traits<i, T0, T1, T2, T3>::data_type
//get(my_tuple<T0, T1, T2, T3>& tup) {
//	return type_shift_node_traits<i, T0, T1, T2, T3>::get_node(tup.t).data;
//}
//
//int main() {
//	typedef my_tuple<int, char, float> tuple3;
//	tuple3 t3(10, 'm', 1.2f);
//	std::cout << t3.t.data << ' '
//		<< t3.t.next.data << ' '
//		<< t3.t.next.next.data << '\n';
//	std::cout << tuple3::num << '\n';
//	std::cout << get<2>(t3) << '\n'; // �� 0 ��ʼ����Ҫ���� 3�����򽫳��ֲ������ı������
//	
//	std::cin.get(); 
//	return 0;
//}




//#include <iostream>
//
//// Ԫ����
//template<typename T0 = void, typename T1 = void, typename T2 = void, typename T3 = void>
//class meta_container {
//public:
//	typedef T0 type;
//	typedef meta_container<T1, T2, T3, void> next_node; // ������λ��
//	static const int size = next_node::size + 1; // �� null_type ģ���������
//};
//template<> // �������ݹ���ֹ
//class meta_container<void, void, void, void> {
//public:
//	typedef void type;
//	static const int size = 0;
//};
//
//// ����Ԫ�����е�����
//template<typename C, unsigned i>
//class get {
//public:
//	static_assert(i < C::size, "get<C,i>: index exceed num"); // C++11 ���뾲̬����
//	typedef typename get<C, i - 1>::c_type::next_node c_type;
//	typedef typename c_type::type ret_type;
//};
//template<typename C>
//class get<C, 0> {
//public:
//	static_assert(0 < C::size, "get<C,i>: index exceed num"); // C++11 ���뾲̬����
//	typedef C c_type;
//	typedef typename c_type::type ret_type;
//};
//
//// ��Ԫ�����в���ĳ�����ͣ��ҵ������������Ҳ������� -1
//template<typename T1, typename T2> class same_type { public: enum { ret = false }; };
//template<typename T> class same_type<T, T> { public: enum { ret = true }; };
//
//template<bool c, typename Then, typename Else> class IF_ { };
//template<typename Then, typename Else>
//class IF_<true, Then, Else> { public: typedef Then reType; };
//template<typename Then, typename Else>
//class IF_<false, Then, Else> { public: typedef Else reType; };
//
//template<typename C, typename T>
//class find {
//template<int i> class number { public: static const int ret = i; };
//template<typename C, typename T, int i>
//class find_i {
//public:
//	static const int ret = IF_< same_type<get<C, i>::ret_type, T>::ret,
//		number<i>, find_i<C, T, i - 1> >::reType::ret;
//};
//template<typename C, typename T>
//class find_i<C, T, -1> {
//public:
//	static const int ret = -1;
//};
//public:
//	static const int ret = find_i<C, T, C::size - 1>::ret;
//};
//
//int main() {
//	typedef meta_container<int, int&, const int> mc;
//	int a = 9999;
//	get<mc, 1>::ret_type aref = a;
//	std::cout << mc::size << '\n';
//	std::cout << aref << '\n';
//	std::cout << find<mc, const int>::ret << '\n';
//	std::cout << find<mc, float>::ret << '\n';
//	
//	std::cin.get(); 
//	return 0;
//}




