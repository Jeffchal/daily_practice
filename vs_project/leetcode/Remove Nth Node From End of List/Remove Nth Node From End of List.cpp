#include <iostream>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {} //c++д�������캯������:�������ǹ��캯���Ĳ����б����ڶԳ�Ա������ʼ����
 };
 ListNode *head = NULL;

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

 void Output() {
	 ListNode *current_node = head;     //��ͷ��㿪ʼ����
	 while (current_node != NULL) {
		 cout << current_node->val << " ";
		 current_node = current_node->next;
	 }
	 cout << endl;
 }

 class Solution
 {
 public:
	 ListNode* removeNthFromEnd(ListNode* head, int n)
	 {
		 ListNode** t1 = &head, *t2 = head;
		 for (int i = 1; i < n; ++i)
		 {
			 t2 = t2->next;
		 }
		 while (t2->next != NULL)
		 {
			 t1 = &((*t1)->next);
			 t2 = t2->next;
		 }
		 *t1 = (*t1)->next;
		 return head;
	 }
 };

 //class Solution {
 //public:
	// ListNode* removeNthFromEnd(ListNode* head, int n) {
	//	 auto node = head;
	//	 while (n--)
	//	 {
	//		 node = node->next;
	//	 }
	//	 if (node->next != NULL)
	//		 node->next = node->next->next;
	//	 else
	//		 node->next = NULL;

	//	 return head;
	// }
 //};

int main()
{
	ListNode* Node;
	int num[5] = {1,2,3,4,5};
	for (int i = 1; i <= 5; i++) {
		ListNode *node = new ListNode(num[i-1]);		 //��new�������ÿһ���ڵ㿪�ٿռ�
		  Insert(node, i - 1);							//���ó�Ա����
	}
	Solution Sol;
	//cout << head->val <<" "<< head->next->val<<" "<< head->next->next->val << endl;
	Sol.removeNthFromEnd(head,2);
	Output();

	return 0;
}