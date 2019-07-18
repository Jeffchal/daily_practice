#include <iostream>
#include <vector>
#include <unordered_map>
//#include <allocators>
#include <algorithm>
#include <iterator>
using namespace std;

//���ķ�����������Ȼ��ѭ���Ƚ�
//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		sort(nums1.begin(), nums1.end());
//		sort(nums2.begin(), nums2.end());
//		int n1 = (int)nums1.size(), n2 = (int)nums2.size();
//		int i1 = 0, i2 = 0;
//		vector<int> res;
//		while (i1 < n1 && i2 < n2) {
//			if (nums1[i1] == nums2[i2]) {
//				res.push_back(nums1[i1]);
//				i1++;
//				i2++;
//			}
//			else if (nums1[i1] > nums2[i2]) {
//				i2++;
//			}
//			else {
//				i1++;
//			}
//		}
//		return res;
//	}
//};

//�Լ��ĳ��ԣ���Ҫ����һ���м����飬�ж��ж�����ͬ�����������Ӧ�±�Ԫ�أ�������i=2,a[2]++�������֪���м���Ԫ�ص���2��
//ʧ���ˣ���Ϊͬһ����������Ҳ����ͬԪ�ء�o(�i�n�i)o
//class Solution {
//public:
//	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//		int arr_[1000];
//		for (int i = 0; i < nums1.size(); i++)
//			arr_[i] = 0;
//		for (int i = 0; i < nums1.size(); i++)
//		{
//			arr_[nums1[i]]++;
//		}
//		for (int i = 0; i < nums2.size(); i++)
//		{
//			arr_[nums2[i]]++;
//		}
//		int num_arr = 0;
//		for (int i = 0; i < nums1.size(); i++)
//		{
//			if (arr_[i] == 2)
//				num_arr++;
//		}
//
//		vector<int> arr_copy;
//		for (int i = 0; i < (nums1.size() > nums2.size() ? nums1.size() : nums2.size()); i++)
//		{
//			if (arr_[i] == 2)
//				arr_copy.push_back(i);
//		}
//
//		return arr_copy;
//
//	}
//};


//����set_intersection��������������Χ����㣬Ȼ��ȥ��
//class Solution {
//public:
//	vector<int> intersect(vector<int>& a, vector<int>& b) {
//		sort(a.begin(), a.end());
//		sort(b.begin(), b.end());
//		std::vector<int>::iterator it = set_intersection( a.begin(), a.end(), b.begin(), b.end(), a.begin() );
//		//�ܽ�����������ĵ�����ֻ���漴���ʵ�������Ҫ������Ԫ�ش洢�������ڴ�ռ��vector��string��deque�ĵ��������мӼ����ģ�����map��set��multimap,multiset�ĵ�������û�мӼ����ģ�listҲ������ 
//		//��֪ʶ������ˢleetcode347��ʱ�뵽��
//		int num = it - a.begin();
//		a.resize(num);
//		//a.resize(it - a.begin()); 
//		//a.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), a.begin()), a.end());
//		return a;
//	}
//};

//��������ӳ�䣬��ֵͨ������Ψһ��ʶԪ��
//class Solution {
//public:
//	vector<int> intersect(vector<int>& a, vector<int>& b) {
//		unordered_map<int, int> ctr;
//		for (int i : a)
//			ctr[i]++;
//		vector<int> out;
//		for (int i : b)
//			if (ctr[i]-- > 0)
//				out.push_back(i);
//		return out;
//	}
//};

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> dict;
		vector<int> res;
		for (int i = 0; i < (int)nums1.size(); i++) dict[nums1[i]]++;
		for (int i = 0; i < (int)nums2.size(); i++)
			if (--dict[nums2[i]] >= 0) res.push_back(nums2[i]);
		return res;
	}
};



int main()
{
	vector<int> nums1{ 4,9,5};
	vector<int> nums2{ 9,4,9,8,4};
	Solution sol;
	
	
	for (auto i : sol.intersect(nums1, nums2))
		cout << i << " ";
	cout << endl;

	return 0;
}






//#include <iostream>     // std::cout
//#include <algorithm>    // std::set_intersection, std::sort
//#include <vector>       // std::vector
//
//int main() {
//	int first[] = { 5,10,15,20,25 };
//	int second[] = { 50,40,30,20,10 };
//	std::vector<int> v(10);                      // 0  0  0  0  0  0  0  0  0  0
//	std::vector<int>::iterator it;
//
//	std::sort(first, first + 5);     //  5 10 15 20 25
//	std::sort(second, second + 5);   // 10 20 30 40 50
//
//	it = std::set_intersection(first, first + 5, second, second + 5, v.begin());
//	// 10 20 0  0  0  0  0  0  0  0
//	std::cout << &v[1]<<" "<< &v[2]<<std::endl;
//	v.resize(it - v.begin());                      // 10 20
//
//	std::cout << "The intersection has " << (v.size()) << " elements:\n";
//	for (it = v.begin(); it != v.end(); ++it)
//		std::cout << ' ' << *it;
//	std::cout << '\n';
//
//	return 0;
//}