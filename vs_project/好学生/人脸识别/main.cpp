#include<iostream>
using namespace std;

int main()
{
    int n,m;
	cin >> n >> m ;
	int a[101]={0};
	char hwork[101][101];
	int max,max_sign;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>hwork[i][j];

	for(int j=0;j<m;j++)
	{   
		max_sign=0;
		max=hwork[0][j];
		for(int i=1;i<n;i++)                 //i=1���ų���һ��i=0�������ѭ�������ҵ����ֵ�ڷ���
		{	
			if( hwork[i][j] == max )         //ÿ�ε�һ�ж������������ڣ�a[0]ÿ�ζ�++��a[0]���������Ҳ���ܲ��ǣ�
			{
				a[i]++; 	                //�������ȵĽ����ÿ�����������
			}
			if( hwork[i][j] > max )         
			{
					max=hwork[i][j];
					max_sign=i;		         //��������ѡ�������,ÿ��ֻ��������i��ֵ�������Ҫ�����������ڵ����
			}
		} 
		if(hwork[0][j] > max)               //i=0,�ж�a[0]�Ƿ��֮ǰ�ó������ֵ��
		{
			a[0]++;
		}  
		a[max_sign]++;     
	}


	int num=0;
	for(int i=0;i<n;i++)
	{	
		if(a[i]!=0)
			num++;
	}
	cout << num << endl;

    return 0;
}



