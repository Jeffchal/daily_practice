#include<iostream>
#include<cmath>
#include"line.h"
using namespace std;

int main()
{
Point myp1(1,1),myp2(4,5); //����Point��Ķ���
Line line(myp1,myp2); //����Line��Ķ���
Line line2(line); //���ÿ������캯������һ���¶���
cout<<"The length of the line is :";
cout<<line.GetLen()<<endl;
cout<<"The length of the line2 is :";
cout<<line2.GetLen()<<endl;
}