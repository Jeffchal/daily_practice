#include<iostream>
#include<cmath>
#include "line.h"

using namespace std;

Line::Line(Point xp1,Point xp2)
:p1(xp1),p2(xp2)
{
cout<<"Line���캯��������"<<endl;
double x=double(p1.GetX()-p2.GetX());
double y=double(p1.GetX()-p2.GetY());
len=sqrt(x*x+y*y);
}
//�����Ŀ������캯��
Line::Line(Line &L):p1(L.p1),p2(L.p2)
{
cout<<"Line �������캯��������"<<endl;
len=L.len;
}


//line::~line(void)
//{
//	;
//}


Point::Point(Point &p) //����������ʵ��
{
X=p.X;
Y=p.Y;
cout<<"Point��������������"<<endl;
}


