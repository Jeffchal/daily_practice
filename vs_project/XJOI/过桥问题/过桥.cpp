#include <iostream>
#include <deque>
#include <iterator>
//#include <allocators>
#include <algorithm>

using namespace std;

//ÿ�λ���һ��������������С�ģ�Ȼ�������������ţ��������С��
int main()
{
	int n;int itime=0;
	cin >> n;
	deque <int> bridge_;
	int inumber_bridge;
	for(int i=0;i<n;i++)
	{
		cin >> inumber_bridge; 
		bridge_.push_back(inumber_bridge);
	} 
	
	if( bridge_.size() == 1 )
		cout << inumber_bridge <<endl;

	else
	{
		sort(bridge_.begin(),bridge_.end());          //����С����
	
		int ibiggest,ibigger,ismall,ismaller;
		int isize=bridge_.size();
	
		ismall=bridge_.front();						  //����С��ȡ��
		//itime += ismall;						     
		bridge_.pop_front();
		ismaller=bridge_.front();                     //����С��ȡ��
		//itime += ismaller;
		bridge_.pop_front();
	
		while(bridge_.size())
		{
			//��ʼ��
			ibiggest = bridge_.back();				   //������ȡ��
			bridge_.pop_back();
			itime += ismaller + ismall  + ibiggest ;

			if(bridge_.size())
			{
				ibigger = bridge_.back();				//���δ��ȡ��
				bridge_.pop_back();
				itime += ismaller;
			}		
		}

		if( isize %2 == 0)
			itime += ismaller;
	 
	///////////////���ս��Ϊ (isize-2)/2 ����2*ismaller+ismall+ibiggest����� ��ż���ڼ�һ����Сֵ/////////////

		cout << itime <<endl;
	}

	return 0;
}

// 1 3 4 5 8 10



//#include<bits/stdc++.h>
//using namespace std;
//int a[1000010],ans=0;
//void f(int n)
//{
//	if(n<=2) ans+=a[n];
//	else if(n==3) ans+=a[1]+a[2]+a[3];
//	else
//	{
//		ans+=a[n]+a[1];
//		ans+=min(2*a[2],a[n-1]+a[1]);
//		f(n-2);
//	}
//}
//
//int main()
//{
//	int bridge[100];
//	int i,n;
//	scanf("%d",&n);
//	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
//	sort(a+1,a+n+1);
//	f(n);
//	printf("%d",ans); 
//	return 0;
//}























//void bubble_sort(int arr[], int len) {
//	int i, j;
//	for (i = 0; i < len - 1; i++)
//		for (j = 0; j < len - 1 - i; j++)
//			if (arr[j] > arr[j + 1])
//				swap(arr[j], arr[j + 1]);
//}

//	int *ibridge=new int[n];
//deque <int> vec(100); //(bridge,bridge+100);
//copy( bridge, bridge+50, vec.begin() );
//sort( vec.begin(), vec.end() );
//sort(bridge,bridge+100);
//int *BridgeCopy=new int[n];
//for(int i=0;i<n;i++)
//	BridgeCopy[i]=bridge[i];
//for(int i=0;i<n;i++)
//	cout << BridgeCopy[i] << " "; 
//int *ibridgeoveride=new int[n];