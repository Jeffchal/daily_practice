/*�����������Ȱ�����1�ͱ���������ڵĻ���һ�����俪���ŵ�ֵ�ǵ�3����*/
/*ֻ��Ҫ��֤��������ŵ����ǲ�����������*/

#include <iostream>
#include<cmath>
using namespace std;

bool isp(long long x)
{  int t=0;
   if (x==1) return 0;
   else if (x==2) return 1;
   else
    for( long long i=2; i<=sqrt(x*1.0); i++ )
	  if(x % i==0) {t=1;break;}
		if(t==0)
		  return 1;
        else return 0;
}
int main()
{
   long long n;
   while(cin>>n)
   {
    if( ((long long)(sqrt(n*1.0))*(long long)(sqrt(n*1.0))==n) && isp(int(sqrt(n*1.0))) )
      cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
   }
  return 0;
}