/* 
    ��Ŀ�� ��37%x=5��x�ĸ���
	����˼·���ҹ��ɷ��� x ȡֵΪ 32��16��8�� ��37-5�ҵ������Ǹ�����Ȼ����������16,8��32��Լ�����Ҵ���5. 
*/

#include<iostream>
#include<algorithm>
#include <cmath>

using namespace std;



using namespace std;
int main()
{
	int a,b,c,ans=0;
	a=5/2;
	cin>>a>>b;
	c=a-b;
	for(int i=1;i<=(int)sqrt((double)c);i++)
	{
		if(c%i==0)
		{
			if(i>b)
				ans++;
			if(c/i>b && i!=(int)sqrt((double)c))
				ans++;
		}
	}
	if(a!=b)
		cout<<ans<<endl;
	else
		cout<<"infinity";
	return 0;
}


/* ��һ����������Լ��*/
/*
#include <iostream>
#include <cstring>
#include <algorithm>

#define maxn 100

using namespace std;

int yueShu[maxn],length;

void approximateNumber(int n){
	int i;
	for(i=1;i*i<n;i++){
		if(n%i == 0){
			yueShu[length ++] = i;
			yueShu[length ++] = n/i;
		}
	}

	if(i*i == n)
		yueShu[length ++] = i;
}

void print(){
	cout<<yueShu[0];
	for(int i=1;i<length;i++)
		cout<<" "<<yueShu[i];
	cout<<endl;
}

int main(){
	int n;
	while(cin>>n){
		memset(yueShu,0,maxn*sizeof(int));
		length = 0;

		approximateNumber(n);
		sort(yueShu,yueShu + length);

		print();
	}
	return 0;
}
*/

