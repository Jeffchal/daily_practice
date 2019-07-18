#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>

/**
* cstdio�ǽ�stdio.h��������C++ͷ�ļ�����ʽ��ʾ������
*stdio.h��C��׼�������е�ͷ�ļ�������standard buffered input&output��
*�ṩ���������ֵ����������������������Ļ���ļ��ȣ���
*/

/**
*conio��Console Input/Output������̨����������ļ�д�����ж�����ͨ������̨���������������������ĺ�����
*��Ҫ��һЩ�û�ͨ�������̲����Ķ�Ӧ����������getch()()�����ȵȡ�
*/

using namespace std;

struct node
{
	int data;
	node *next;
};
typedef struct node node, *list;

// ����������
node *creat()
{
	node *head, *p;
	head = new node;
	p = head;

	int x, cycle = 1;
	while (cycle)
	{
		cout << "Please input the data for single linker : ";
		cin >> x;

		if (x != 0)
		{
			node *s = new node;
			s->data = x;
			cout << "Input data : " << x << endl;

			p->next = s;
			p = s;
		}
		else
		{
			cycle = 0;
			cout << "Input done! " << endl;
		}
	}

	head = head->next;
	p->next = NULL;
	//cout << "\nFirst data of single linker is " << head->data << endl;

	return head;
}

// ������ⳤ
int length(node *head)
{
	int n = 0;
	node *p = head;

	while (p != NULL)
	{
		p = p->next;
		n++;
	}

	return n;
}

// �������ӡ
void printL(node *head)
{
	node *p = head;

	while (p != NULL)
	{
		cout << "Single Linker data is " << p->data << endl;
		p = p->next;
	}
}

// ���������
node *insert(node *head, int num)
{
	node *p0, *p1, *p2;
	p1 = head;

	p2 = new node;
	p0 = new node; // ����ڵ�
	p0->data = num;// ��������

	while (p0->data > p1->data && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;// p0,p1��p2λ��: p2->p1->p0
	}

	if (p0->data <= p1->data)
	{
		if (p1 == head)
		{// ͷ��ǰ�β��� p0��p1λ��: p0->p1->...
			head = p0;
			p0->next = p1;
		}
		else
		{// �����м�ڵ� p0,p1��p2λ��: p2-> p0 -> p1
			p2->next = p0;
			p0->next = p1;
		}
	}
	else
	{   // β������ڵ� p0,p1��p2λ��: p2->p1->p0->NULL
		p1->next = p0;
		p0->next = NULL;
	}
	return head;
}

// ������ɾ��
node *del(node *head, int num)
{
	node *p1, *p2;
	p2 = new node;
	p1 = head;

	while (num != p1->data && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;// p1��p2λ��: p2->p1		
	}

	if (num == p1->data)
	{
		if (p1 == head)// ɾ��ͷ�ڵ�
		{
			head = p1->next;
			delete p1;
		}
		else
		{
			p2->next = p1->next;
			delete p1;
		}
	}
	else
	{
		cout << num << " could not been found in the current single linker!" << endl;
	}
	return head;
}

//=============��������====================
node *insertSort( node *head )
{
	node  *p1, *prep1, *p2, *prep2, *temp;
	prep1 = head->next;
	p1 = prep1->next;
	//prep1��p1�Ƿ���Ҫ�ֶ�����
	bool flag;

	while (p1 != NULL)
	{
		flag = true;
		temp = p1;
		//�����ǵ�����������ֻ�ܴ�ͷ����ʼ����
		for (prep2 = head, p2 = head->next; p2 != p1; prep2 = prep2->next, p2 = p2->next)
		{
			//���ֵ�һ���ϴ�ֵ
			if (p2->data > p1->data)
			{
				p1 = p1->next;
				prep1->next = p1;
				prep2->next = temp;
				temp->next = p2;
				flag = false;
				break;
			}
		}
		//�ֶ�����prep1��p1
		if (flag)
		{
			prep1 = prep1->next;
			p1 = p1->next;
		}
	}
	return head;
}

////��������
//node *insertionSortList(node *head) {
//	// IMPORTANT: Please reset any member data you declared, as
//	// the same Solution instance will be reused for each test case.
//	if (head == NULL || head->next == NULL)return head;
//	node *p = head->next, *pstart = new node(0), *pend = head;
//	pstart->next = head; //Ϊ�˲������㣬���һ��ͷ���
//	while (p != NULL)
//	{
//		node *tmp = pstart->next, *pre = pstart;
//		while (tmp != p && p->data >= tmp->data) //�ҵ�����λ��
//		{
//			tmp = tmp->next; pre = pre->next;
//		}
//		if (tmp == p)pend = p;
//		else
//		{
//			pend->next = p->next;
//			p->next = tmp;
//			pre->next = p;
//		}
//		p = pend->next;
//	}
//	head = pstart->next;
//	delete pstart;
//	return head;
//}


int main()
{
	cout << "***����������***" << endl;
	node *head = creat();
	cout << endl;

	cout << "***��������***" << endl;
	int n = length(head);
	cout << "The length of input single linker is " << n << "." << endl;
	cout << endl;

	cout << "***��ӡ������***" << endl;
	printL(head);
	cout << endl;

	cout << "****����ڵ�****" << endl;
	cout << "Please input the data for inserting operate : ";
	int inData;
	cin >> inData;
	head = insert(head, inData);
	printL(head);
	cout << endl;

	cout << "****ɾ���ڵ�****" << endl;
	cout << "Please input the data for deleting operate : ";
	int outData;
	cin >> outData;
	head = del(head, outData);
	printL(head);
	cout << endl;

	cout << "****��������****" << endl;
	//��һλ��ַ���Դ��ָʾ�����ӵڶ�λ��ʼ��������
	node *mylist = new node[sizeof(node)];
	mylist->data = 0;
	mylist->next = NULL;

	int len = length(head);
	int i = 0;
	node * cur = mylist;


	node *headcopy = head;
	while (len--)
	{
		//node * newNode = (node *)malloc(sizeof(node));   
		node *newNode = new node[sizeof(node)];            
		newNode->data = headcopy->data;
		newNode->next = NULL;
		cur->next = newNode;
		cur = cur->next;
		headcopy=headcopy->next;
	}

	head = insertSort(mylist);
	head = del(head, 0);
	//node *insertionSortList(node *head);
	printL(head);

	return 0;
}

