#include "Mylist.h"

int main(int argc, const char * argv[])
{

	// insert code here...
	List list;

	list.creat();
	list.print();
	cout << "insert������ԣ�" << endl;
	list.insert_head(30);
	list.insert_head(20);
	list.insert_tail(10);
	list.insert_head(40);
	list.insert_pos(10, 5);					//��10ǰ�����5
	list.print();
	cout << "eraseɾ�����ԣ�" << endl;
	list.erase(10);                         //ɾ��Ԫ��10
	list.print();
	cout << "reverse��ת���ԣ�" << endl;
	list.reverse();							//��ת����
	list.print();
	cout << "updata�滻���ԣ�" << endl;
	list.updata(5, 8);						//�滻Ԫ��
	list.print();
	list.creat();
	list.print();
	cout << "ð������������:" << endl;
	//list.select_sort();
	list.bubble_sort();
	list.print();

}