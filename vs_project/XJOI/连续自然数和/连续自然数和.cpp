#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

/*ö�ٷ�*/
//int main()
//{
//	int n;
//	cin>>n;
//
//	for(int i=1;i<=n/2;i++)
//	{
//		int j;
//		int sum=0;
//		for(j=i;j<n;j++)
//		{
//			sum+=j;
//			if(sum>=n)
//				break;
//		}
//
//		if(sum==n)
//			cout<<i<<" "<<j<<endl;
//	}
//
//	return 0;
//}

/*ö����˺��Ҷ�*/
//int main()
//{
//	long long n,s=1,sum=0;
//	scanf("%lld",&n); 
//	for(int i=1;i<n;i++)
//	{
//		sum+=i;
//		while(sum>n)
//			sum-=s++;
//		if(sum==n)
//			cout<<s<<" "<<i<<endl;
//
//	}
//	return 0;
//} 

/*�����������õȲ����к͵Ĺ�ʽ���*/
//int main()
//{
//	long long n,i,j,sum=0;
//	cin>>n;
//	for(i=1;i<n;i++)
//		for(j=i+1;j<n;j++)
//			if((i+j)*(j-i+1)/2==n)
//				cout<<i<<" "<<j<<endl;
//			else if((i+j)*(j-i+1)/2>n)
//				break;
//	return 0;
//} 

/*����������ǰ���㲢����ǰn����֮�ͣ�Ȼ����жԱ�*/
//int main()
//{
//	long long d[2000005];
//	long long s=0;
//	d[0]=0;
//	for(int i=1;i<=2000000;i++)
//	{
//		s+=i;
//		d[i]=s;
//	}
//
//	long long n;
//	while(cin>>n)
//	{
//		int j=0;
//		for(int i=1;i<n;i++)
//		{
//			for(;j<n;j++)   //�����ĸ��Ӷ���ʵΪO(n);
//			{
//				long long x=d[i]-d[j];
//				if(x==n)
//				{
//					cout<<j+1<<' '<<i<<endl;
//
//				}
//				else if(x<n) break;
//			}
//		}
//
//	}
//}


/*
	��Ŀ����ת��Ϊ���Ȳ�����n����֮��ΪSn��
	�Ȳʽ��Sn=n(a1+an)/2=n[2a1+(n-1)d]/2������n,����a1,����d��
	           k=��(2*Sn)=��n(a1+an)=��n[2a1+(n-1)d]
	Sn=na1+0.5*(n^2-n)=0.5n^2+(a1-0.5)n   
	n^2+(2a1-1)n-2Sn=0    һԪ���η���ax^2+bx+c=0     ��x=(-b+��)/2a
 */
//int main()
//{
//	LL m;
//	cin>>m;
//	LL n,a1,i;
//	double r;
//	LL b,c,d;
//	for(i=0;i<=m;i++)
//	{   
//		a1=i;
//		b=(2*a1-1);
//		c=-2*m;
//		d=b*b-4*c;//delta�б�ʽ
//		r=-b+sqrt(d);//�����ʽ�ֺ�������һ�Ѷ�����
//		if(r==(int)r&&r>0)//ĳЩʱ��-b�����sqrt(d)������rΪ�����������������������
//		{
//			n=r/2;            //��/2a����x�Ľ⣬��n���𰸵�������֮����n����
//			if(a1==a1+n-1)
//				continue;//����ֻ��һ������
//			cout<<a1<<' '<<a1+n-1<<' '<<endl;    
//		}
//	}
//	return 0;
//} 


//˼·���Ȳ����У���Ϊ��1��ʼ����������β��-����+1����������һ���Ͷ�Ӧ����������ż��ͬ��
//������Ϊ��������Ӧ������ĺ���Ϊż����
//���磺1 4 �����������а���4���1��2��3��4��Ϊż������1+4=5Ϊ������
//��Ȼ��һ�����������У���ô���ǵĺ͵������ǵ�ƽ������������ƽ��������Ϊ0.5��������������2����ƽ������Ϊ������
//������Ϊ���������Ӧ��λ��ͱ�Ϊż����������Ϊż�������Ӧ��λ��ͱ�Ϊ������
//�����Ͷ�Ӧ��λ��Ͳ�����ͬΪ�棬��(x+2*m/x)%2һ��Ϊ������
int main(){
	int m;		
	cin>>m;											
	for( int x=sqrt((double)(2*m)) ; x>1 ; x-- )    //x��������Ȼ�εĸ���(����)����xΪ��������β�����Ĳ�+1
		if( (2*m)%x==0 && (x+2*m/x)%2 )				//2m��x�ı�����x+y������
		{
			int y=2*m/x;							//2����ƽ����,��y�Ƿ��������������β��ĺͣ���ֹƽ������С����   
			cout<<(y-x+1)/2<<" "<<(y+x-1)/2<<endl;  //ƽ����-����*0.5��ƽ����+����*0.5����֮ǰ�����������С     ��֤��(y+x-1)/2-(y-x+1)/2=x-1����x��,��
		}
		return 0;
}


/*
     ��˹��
     ����M���еȲ�������͹�ʽ�ã�������[x,y]��M=��x+y��*��x-y+1��/2,˳����һ�� x-y+1 Ϊ��Ȼ������
	  y^2-y=x^2+x-2*M����һ������ͬʱ��һ��1/4 �ɵ� ��y-1/2)^2=��x+1/2)^2-2*M;
	  y=��(x^2+x-2M+1/4)-1/2=��((x+1/2)^2-2M��+1/2
 */
/*
	n^2+(2a1-1)n-2Sn=0    һԪ���η���ax^2+bx+c=0      a=1,b=(2a1-1),c=-2Sn=-2m
	x^2+(2a1-1)x-2Sn=0;  ��y-1/2��^2=��x+1/2)^2-2*M;   �Գƣ�ֻ��Ҫһ�룬�����һ�����x,yֵ�Ե�
	((x + y) * (y - x + 1) / 2 == Sn) ; y^2+y=2Sn+X^2-x 
//*/
//int main()
//{
//	int x = 1, y = 0, Sn;
//
//	scanf("%d", &Sn);
//	for (; y < Sn / 2; x++, y = (int)(sqrt(Sn * 2 - x+ x * x + 0.25) - 0.5))
//		if ((x + y) * (y - x + 1) / 2 == Sn) printf("%d %d\n", x,y);                      //42�֣��д���
//
//	return 0;
//}



//https://www.luogu.org/blog/boshi/solution-p1147
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cstdio>
//#include <vector>
//using namespace std;
//int M;
//typedef struct node_t
//{
//	int l,r;
//	inline bool operator < (const node_t t) const
//	{
//		return l<t.l;
//	}
//}node;
//vector<node>ans;
//
//inline void work()
//{
//	node t;
//	for(register int i=M;i>=2;i--)
//		if((i&1)&&(M%i==0))
//		{
//			t=(node){M/i-i/2,M/i+i/2};
//			if(t.l==0)t.l++;
//			else if(t.l<0)t.l=-t.l+1;
//			if(t.l>t.r)swap(t.l,t.r);
//			ans.push_back(t);
//		}
//		sort(ans.begin(),ans.end());
//		for(register int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].l,ans[i].r);
//}
//int main()
//{
//	scanf("%d",&M);
//	work();
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//int M;
//typedef struct node_t
//{
//	int l,r;
//	inline bool operator < (const node_t t)const{return l<t.l;}
//}node;
//vector<node>ans;
//inline void work()
//{
//	node t;
//	for(register int i=2;i*i<=M;++i)
//		if((i&1)&&(M%i==0))
//		{
//			//node a={M/i-i/2,M/i+i/2};
//			//t=a;
//			t= node {M/i-i/2,M/i+i/2};
//			if(t.l==0)t.l++;
//			else if(t.l<0)t.l=-t.l+1;
//			if(t.l>t.r)swap(t.l,t.r);
//			ans.push_back(t);
//		}
//		for(register int i=1;i*i<M;++i)
//			if(((M/i)&1)&&(M%i==0))
//			{
//				//node b={i-(M/i)/2,i+(M/i)/2};    
//				//t=b;
//				t=node {i-(M/i)/2,i+(M/i)/2}        //c++13֧�����Ը�ֵ
//				if(t.l==0)t.l++;
//				else if(t.l<0)t.l=-t.l+1;
//				if(t.l>t.r)swap(t.l,t.r);
//				ans.push_back(t);
//			}
//			sort(ans.begin(),ans.end());
//			for(register int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].l,ans[i].r);
//}
//
//int main()
//{
//	scanf("%d",&M);
//	work();
//	return 0;
//}