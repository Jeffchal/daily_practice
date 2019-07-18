#include <iostream>
using namespace std;

struct Node {										//�ڵ�ṹ
	int data;
	Node * next;
	Node(const int& d) :data(d), next(NULL) {}
};

class List {
public:
	List() { create_List(); }
	~List() { }//clear(); }
	void create_List();									//����ͷ���
	void insert_head(const int& data);					//��ͷ�����룬�Ƚ����������
	void insert_tail(const int& data);					//��β�����룬�Ƚ��ȳ�������
	void creat();										//��β����������
	void insert_pos(const int& d, const int& d1);		//��ָ��λ�ò���
	void erase(const int& d);							//ɾ��ָ�����ݵĽڵ�
	void updata(const int& d, const int& d1);			//�޸�ָ������
	void reverse();										//��ת������
	void print();										//��ӡ
	void select_sort();									//����ѡ������(����)
	void bubble_sort();									//����ð������(����)

	Node * head;										//ͷ�ڵ�
	void clear();										//����������

private:										
	//void clear();										//����������
	Node* find(const int& d);
};
Node* List::find(const int& d) {						//��������d����һ���ڵ�λ�õĺ���
	Node * p = head;
	for (; p; p = p->next) {
		if (p->next->data == d)
			break;
	}
	return p;
}

void List::clear() {									//����������
	Node * p = head;
	//��ͷ�ڵ㿪ʼѭ��ɾ��
	while (p) {
		Node * q = p->next;
		delete p;
		p = q;
	}
}
//void List::clear() {									//����������
//	Node * tmpNode = NULL;
//	Node * p = head->next;
//	while (p != NULL)
//	{
//		tmpNode = p->next;
//		delete p;
//		p = tmpNode;
//	}
//	delete tmpNode;
//	tmpNode = NULL;
//
//	delete head;
//	p = NULL;
//
//}
void List::create_List()								//����ͷ���
{
	head = new Node(0);
}


void List::insert_head(const int& data)					//��ͷ������һ���ڵ㣬head->p2->p1
{
	Node * tmpNode = new Node(data);
	tmpNode->next = head->next;
	head->next = tmpNode;

	tmpNode = NULL;
}

void List::insert_tail(const int& data)					//��β������һ���ڵ㣬heap->p1->p2
{
	Node * tmpNode = new Node(data);
	tmpNode->next = NULL;

	Node * p = NULL;
	p = head;
	while (p->next != NULL)
	{
		p = p->next;           //��p�Ƶ�β��
	}

	p->next = tmpNode;

	//delete tmpNode;
	tmpNode = NULL;
	//delete p;
	p = NULL;
}

void List::creat()										//��β����������
{
	Node *p = head;
	while (p->next != NULL)
	{
		p = p->next;           //��p�Ƶ�β��
	}

	int x, cycle = 1;
	cout << "creat������� (����0ֹͣ) : ";
	while (cycle)
	{
		cin >> x;

		if (x != 0)
		{
			Node *s = new Node(x);
			p->next = s;
			p = s;
		}
		else
		{
			cycle = 0;
			//cout << "Input done! Output Result: " << endl;
		}
	}

	p->next = NULL;

}

void List::print()									//��ӡ����
{
	cout << "-----------------------�����ڵ�Ԫ�أ�";
	for (Node * p = head->next; p; p = p->next) {
		cout << p->data << " ";
	}
	cout << endl;
}

void List::insert_pos(const int& d, const int& d1)	//��dλ��֮ǰ����d1
{
	Node * p = find(d);
	Node * q = new Node(d1);
	q->next = p->next;
	p->next = q;
}


void List::erase(const int& d)						//ɾ��
{
	Node * p = find(d);
	Node *q = p->next;								//��Ϊp����һ���ڵ��λ�ã���q������Ҫɾ���Ľڵ�ĵ�ַ											
	p->next = p->next->next;						//ͨ������һ���ڵ��nextָ��ָ��Ҫɾ���ڵ��nextָ��־��Ľڵ�ʵ�ֶϿ�Ҫɾ���ڵ��Ŀ��

	delete q;										//ɾ��Ҫɾ���Ľڵ�q
}

void List::updata(const int& d, const int& d1)		//�޸�ָ������
{
	Node * p = find(d);
	p->next->data = d1;
}

void List::reverse()								//��ת����
{
	Node * p = head->next;							//ͷ���֮��ĵ�1���ڵ�
	Node * q = head->next->next;					//ͷ���֮��ĵ�2�ڵ�
	Node * m = head->next->next->next;				//ͷ���֮��ĵ�3���ڵ�
	p->next = NULL;									//��ͷ�ӵ�֮��ĵ�1���ڵ��nextָ����Ϊ��
													//����m�Ƿ�Ϊ�����ж� �Դ�����ÿһ���ڵ�
	while (m) {
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}
	q->next = p;									//�����һ���ڵ�����
	head->next = q;									//��ͷ����ָ���µĵĵ�1���ڵ�(֮ǰ�����һ���ڵ�)

}

void List::bubble_sort()							//ð������
{
	Node *p;
	int temp;

	int flag;
	while (true)
	{
		flag = 0;
		for (p = head; p->next != NULL; p = p->next)
		{
			if (p->data > p->next->data)
			{
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void List::select_sort()								//ѡ������
{
	Node * p, *q;
	int temp;

	for (p = head; p != NULL; p = p->next)
		for (q = p->next; q != NULL; q = q->next)
		{
			if (p->data > q->data)
			{
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
}


//class Solution {
//public:
//	Node* mergeTwoLists(Node* l1, Node* l2) {
//		if (!l1 || l2 && l1->data > l2->data) swap(l1, l2);
//		if (l1) l1->next = mergeTwoLists(l1->next, l2);
//		return l1;
//	}
//};
class Solution {
public:
	Node *mergeTwoLists(Node *l1, Node *l2) {
		Node dummy(INT_MIN);
		Node *tail = &dummy;

		while (l1 && l2) {
			if (l1->data < l2->data) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
};

int main(int argc, const char * argv[])
{
	List list2;
	list2.creat();
	list2.print();

	List list3;
	list3.creat();
	list3.print();

	List list4;
	//������list2��list3��new����ָ�뱻�ظ��ͷţ���
	list4.head->next = Solution().mergeTwoLists(list2.head->next, list3.head->next);
	list4.print();
	list4.clear();

	return 0;
}