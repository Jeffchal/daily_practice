#include <vector>


class Solution {
public:
	void rotate(std::vector<int>& v, int k) {                               //������ת��Χ�ڵ�Ԫ�أ�
		std::rotate(v.rbegin(), v.rbegin() + k % v.size(), v.rend());  //��ת��Χ��Ԫ�ص�˳��ʹ�м�[first,last)ָ���Ԫ��v.rbegin() + k % v.size()��Ϊ�µĵ�һ��Ԫ�ء�
	}
};