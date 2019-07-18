//Count and Say
//Ĭ��Ϊֻ��һ�������ظ�count=1�������������ͬ����count++�����򲻱䡣


#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
			if (n == 0) return "";
			string res = "1";
			string cur ;
			while (--n) {
				cur = "";

				for (int i = 0; i < res.size(); i++) {
					int count = 1;
					while ((i + 1 < res.size()) && (res[i] == res[i + 1])) {
						count++;
						i++;
					}
					cur += to_string(count) + res[i];
				}

				res = cur;
			}
			return res;
		}
};

//class Solution {
//public:
//	string countAndSay(int n) {
//
//	}
//};

int main()
{
	Solution m_sol;
	int n = 6;
	cout << m_sol.countAndSay(n);

	return 0;
}