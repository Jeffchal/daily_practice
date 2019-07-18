#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//�ڵ�ṹ
struct node
{
	int val;
	struct node * next;
};
typedef struct node node, *list; // *list = node node,listָ��ָ��nodeĬ�϶���

//��ӡ����
void printList(list mylist);
////������

////��������
void insertSort(list mylist);
////ð������
void bubbleSort(list mylist);
////��ѡ��
void selectSort(list mylist);
////��������
void quickSort(list mylist);

int main(void)
{
	int arr[] = { 8, 5, 1, 7, 4, 2, 9, 6, 3, 8 };
	//�����������ͷ���ĵ�������
	//list mylist = (list)malloc(sizeof(node));
	//list mylist=new list[sizeof(node)];
	node *mylist = new node[sizeof(node)];
	mylist->val = 0;
	mylist->next = NULL;
	int len = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	node * cur = mylist; 
	while (i < len)
	{
		//node * newNode = (node *)malloc(sizeof(node));   //���ⴴ����һ��node,�����ݸ��Ƶ�mylist�ڶ�λ��ַ
		node *newNode = new node[sizeof(node)];            //ʹ��mylist��һλ���������ݣ��������prep2ָ��
		newNode->val = arr[i];
		newNode->next = NULL;
		cur->next = newNode;
		cur = cur->next;
		i++;
	}
	insertSort(mylist);
	//bubbleSort(mylist);
	//selectSort(mylist);
	//quickSort(mylist);
	printList(mylist);

	return 0;
}

void printList(list mylist)
{
	node * cur = mylist->next;
	while (cur != NULL)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

//=============��������====================
void insertSort(list mylist)
{
	if ((mylist->next == NULL) || (mylist->next->next == NULL))
	{
		return;
	}

	node * head, *p1, *prep1, *p2, *prep2, *temp;
	head = mylist;
	prep1 = head->next;
	p1 = prep1->next;
	//prep1��p1�Ƿ���Ҫ�ֶ�����
	bool flag;

	while (p1 != NULL)
	{
		flag = true;
		temp = p1;
		//�����ǵ�����������ֻ�ܴ�ͷ����ʼ����
		for (prep2 = head, p2 = prep2->next; p2 != p1; prep2 = prep2->next, p2 = p2->next)
		{
			//���ֵ�һ���ϴ�ֵ
			if (p2->val > p1->val)
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
}

//=============ð������====================    ��Bug

void bubbleSort(list mylist)
{
	if ((mylist->next == NULL) || (mylist->next->next == NULL))
	{
		return;
	}

	node *head, *pre, *cur, *next, *end, *temp;
	head = mylist;
	end = NULL;
	//������ͷ��ʼ���ϴ�ֵ�����
	while (head->next != end)
	{
		for (pre = head, cur = pre->next, next = cur->next; next != end; pre = pre->next, cur = cur->next, next = next->next)
		{
			//���ڵĽڵ�Ƚ�
			if (cur->val > next->val)
			{
				cur->next = next->next;
				pre->next = next;
				next->next = cur;
				temp = next;
				next = cur;
				cur = temp;
			}
		}
		end = cur;
	}
}

//=============��ѡ������================
void selectSort(list mylist)
{
	if ((mylist->next == NULL) || (mylist->next->next == NULL))
	{
		return;
	}

	node * head, *prep1, *p1, *prep2, *p2, *premin, *min, *temp;
	head = mylist;
	for (prep1 = head, p1 = prep1->next; p1->next != NULL; prep1 = prep1->next, p1 = prep1->next)
	{
		//������С�ڵ�
		premin = prep1;
		min = p1;
		for (prep2 = p1, p2 = prep2->next; p2 != NULL; prep2 = prep2->next, p2 = prep2->next)
		{
			if (min->val > p2->val)
			{
				premin = prep2;
				min = p2;
			}
		}

		if (p1 != min)
		{
			//һ��Ҫע��������
			if (p1->next == min)
			{
				temp = min->next;
				prep1->next = min;
				min->next = p1;
				p1->next = temp;
			}
			else {
				temp = min->next;
				prep1->next = min;
				min->next = p1->next;
				premin->next = p1;
				p1->next = temp;
			}
		}
	}
}

//=============��������====================

//�����ڵ�
void swap(node * a, node * b)
{
	int temp = a->val;
	a->val = b->val;
	b->val = temp;
}

//���м��
node * partion(node * start, node * end)
{
	if (start == end || start->next == end)
	{
		return start;
	}
	//ȡ��һ��Ԫ����Ϊ��׼Ԫ��
	node * p = start, *q = start, *refer = start;
	//��start��ʼ������һ�α���(��Ϊ�ǵ������޷������������м�����ķ���)
	while (q != end)
	{
		if (q->val < refer->val)
		{
			p = p->next;
			swap(p, q);
		}
		q = q->next;
	}
	swap(p, refer);
	return p;
}
//�ݹ�
void quick_sort(node * start, node * end)
{
	if (start == end || start->next == end)
	{
		return;
	}
	node * mid = partion(start, end);
	quick_sort(start, mid);
	quick_sort(mid->next, end);
}

void quickSort(list mylist)
{
	if ((mylist->next == NULL) || (mylist->next->next == NULL))
	{
		return;
	}
	node * start = mylist->next;
	node * end = NULL;
	quick_sort(start, end);
}

