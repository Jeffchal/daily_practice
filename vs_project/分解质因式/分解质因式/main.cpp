#include<iostream>
using namespace std;
int a[1001];  
int b[1001];
int main()
{
    int n;
    cin>>n;

	/* a[1001]�����з���������ȫ��Ϊ1 */
    for(int i=2;i<=1000;i++)
	 if(a[i]==0)
		for(int j=2*i;j<=1000;j=j+i)
		  a[j]=1;

    int i=2;
    int t=n;
    while( n!=1 ) 
    {
        if( !a[i] )             //�ж��Ƿ�����
        while( n%i==0 && n!=1 )   //����2��3��4������ɹ��������b[1001]�У�������Գ�2�������b[]
        {
            n=n/i;b[i]++;
        } 
        i++;
    }
    if(t==1)
    cout<<"1=1";

    else
    {
	 cout<<t<<"=";
	 i=2;
     while( t%i!=0 )
		i++;
     if(b[i]==1)
		cout<<i;
     else if(b[i]>1)
		cout<<i<<"^"<<b[i];
     for(int j=i+1;j<=1000;j++)
		if(b[j]==1)  cout<<"*"<<j;
		else if(b[j]>1)
    cout<<"*"<<j<<"^"<<b[j];
	}

    return 0;
}