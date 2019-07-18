//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <sstream>  //stringstream�ַ���������ת��
//using namespace std;
//
///**
// * Definition for singly-linked list.
// **/
//struct ListNode {
//	int val;
//	ListNode *next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//
//class Solution {
//public:
//	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//		ListNode dummy(INT_MIN);
//		ListNode *tail = &dummy;
//
//		while (l1 && l2) {
//			if (l1->val < l2->val) {
//				tail->next = l1;
//				l1 = l1->next;
//			}
//			else {
//				tail->next = l2;
//				l2 = l2->next;
//			}
//			tail = tail->next;
//		}
//
//		tail->next = l1 ? l1 : l2;
//		return dummy.next;
//	}
//};
//
//void trimLeftTrailingSpaces(string &input) {							//����߿�ʼɾ������ո�
//	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { //��������[first,end)�е�һ��ֵ���ڿո��Ԫ�ص�λ��
//		return !isspace(ch);									//isspace()�ж�һ���ַ��Ƿ��ǿհ׷�
//	}));
//}
//
//void trimRightTrailingSpaces(string &input) {							//���ұ߿�ʼɾ������ո�
//	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
//		return !isspace(ch);
//	}).base(), input.end());
//}
//
//vector<int> stringToIntegerVector(string input) {		//�ַ�������������
//	vector<int> output;
//	trimLeftTrailingSpaces(input);
//	trimRightTrailingSpaces(input);
//	input = input.substr(1, input.length() - 2);		//��ȡ��1��length() - 2���ַ�����ȥ�������"[]"��"\n"
//	stringstream ss;
//	ss.str(input);
//	string item;
//	char delim = ',';
//	while (getline(ss, item, delim)) {
//		output.push_back(stoi(item));					//���ַ���ת��Ϊ����
//	}
//	return output;
//}
//
//ListNode* stringToListNode(string input) {				//�ַ���������ڵ�
//	// Generate list from the input
//	vector<int> list = stringToIntegerVector(input);
//
//	// Now convert that list into linked list
//	ListNode* dummyRoot = new ListNode(0);              //����ͷ�ڵ�
//	ListNode* ptr = dummyRoot;
//	for (int item : list) {
//		ptr->next = new ListNode(item);
//		ptr = ptr->next;
//	}
//	ptr = dummyRoot->next;
//	delete dummyRoot;
//	return ptr;
//}
//
//string listNodeToString(ListNode* node) {			//����ڵ㵽�ַ���
//	if (node == nullptr) {
//		return "[]";
//	}
//
//	string result;
//	while (node) {
//		result += to_string(node->val) + ", ";		 //����ֵת��Ϊ�ַ��������ض�Ӧ���ַ�����
//		node = node->next;
//	}
//	return "[" + result.substr(0, result.length() - 2) + "]";
//}
//
//int main() {
//	string line;
//	while (getline(cin, line)) {
//		ListNode* l1 = stringToListNode(line);
//		getline(cin, line);
//		ListNode* l2 = stringToListNode(line);
//
//		ListNode* ret = Solution().mergeTwoLists(l1, l2);
//
//		string out = listNodeToString(ret);
//		cout << out << endl;
//	}
//	return 0;
//}
