// A C++ program to demonstrate the use of constexpr 
#include<iostream> 
#include<time.h>   //�õ�clock()����
using namespace std;

long int fib(int n)
{
	return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

int main()
{
	int begintime, endtime;
	begintime = clock();	//��ʱ��ʼ
	// value of res is computed at compile time.  
	long int res = fib(30);
	cout << res << endl;
	endtime = clock();	//��ʱ����
	cout << endtime - begintime << endl;

	return 0;
}