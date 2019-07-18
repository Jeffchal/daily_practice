//

#include <iostream>
using namespace std;


//�ṹ�嶨�� Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}  //c++д�������캯������:�������ǹ��캯���Ĳ����б����ڶԳ�Ա������ʼ����
};
ListNode *head = NULL;

//�ṹ�����
void Insert(ListNode *node, int position) {		  //position��ʾҪ�����λ��
	if (position == 0) {							  //������ǵ�0��λ��,Ϊ�˷��㣬�������ҹ涨ͷ���Ϊ��0���ڵ�
													 //��ô���������ǵ�0��λ�õĻ�,˵������Ľڵ�Ҫ��Ϊ�µ�ͷ���
													 //������֮ǰ��û��ͷ���
		node->next = head;
		head = node;								  //���ͷ���ĸ���,��ʾͷ���������node�ڵ�
		return;
	}
	ListNode *current_node = head;					   //��ͷ��㿪ʼ���������λ��
	int i = 0;										   //��ʾ�Ѿ��������Ľڵ���Ŀ
	while (current_node->next != NULL && i < position - 1) {
		//����Ѱ��Ҫ�����λ�õ�ǰһ��λ��,Ȼ����������λ�õĽڵ�����һ��λ�õĽڵ�֮��
		current_node = current_node->next;            //���ϸ���current_node��ֵ
		i++;
	}
	if (i == position - 1) {							//�ҵ��˲����λ�ã��ȸ��²���ڵ��ָ����,��¼��ǰ��������λ�õ���һ���ڵ�
													   //Ȼ���ٽ���ǰ��Ľڵ�
		node->next = current_node->next;
		current_node->next = node;
	}
}

//�ṹ�����
void Output() {
	ListNode *current_node = head;     //��ͷ��㿪ʼ����
	while (current_node != NULL) {
		cout << current_node->val << " ";
		current_node = current_node->next;
	}
	cout << endl;
}

//����ʵ��
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = NULL;
		ListNode* curr = head;
		while (curr != NULL) {
			ListNode* nextTemp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nextTemp;
		}
		return prev;
	}
};



//������
int main()
{
	ListNode* Node;

	//�����������
	int num[5] = { 1,2,3,4,5 };
	for (int i = 1; i <= 5; i++) {
		ListNode *node = new ListNode(num[i - 1]);		 //��new�������ÿһ���ڵ㿪�ٿռ�
		Insert(node, i - 1);							//���ó�Ա����
	}


	Output();

	Solution Sol;
	head = Sol.reverseList(head);
	Output();

	return 0;
}