#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> scores(5);
	/*for(int i=0;i<5;i++)
	cin>>scores[i];*/
	//int *pd=scores.begin();                 //Error:�����ڴ�"std::_Vector_iterator<std::Vector_val<int,std::allocator<int>>>"��"int *"���ʵ�ת������

	//vector<int>::iterator pd =scores.begin();  	//auto pd=scores.begin();ͬ������ 
	//*pd =22.3;
	//cout << *pd << endl;
	//++pd;
	//cout << *pd << endl;

	double temp;
	while(cin>>temp && temp>=0)
		scores.push_back(temp);
	cout << "You entered " <<scores.size()<<" scores\n";


	return 0;
}