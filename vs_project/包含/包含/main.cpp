////#include <stdio.h>
////#include <stdlib.h>
//#include <iostream>
//using namespace std;
//
//class A
//{
//private:
//    int x;
//public:
//    A(int i) :x(i)
//    {
//        cout << "A's constructor" << endl;
//    }
//    //A(A &a)											//A�ĸ��ƹ��캯����
//    //{
//    //    x = a.x;
//    //    cout << "A's copy constructor" << endl;
//    //}
//    void getx()
//    {
//        cout << "A's a is " << x << endl;
//    }
//    ~A()
//    {
//        cout << "A's destructor" << endl;
//    }
//};
//
//class B
//{
//private:
//    A a;
//    int z;
//public:
//    B(int x,int z) :a(x), z(z)
//    {
//        cout << "B's constructor" << endl;
//    }
//
//    A& getA()                      // &���ÿ��Բ��õ��ø��ƹ��죬ȥ������������ֶ����һ����������
//    {
//        return a;
//    }
//    ~B()
//    {
//        cout << "B's destructor" << endl;
//    }
//};
//
//void playstage()
//{
//    B b1(1,2);
//    b1.getA().getx();
//}
//
//void main()
//{
//    playstage();   
//}


#include <iostream>
using namespace std;
 
class Base
{
public:
Base (int v, char z) {x=v;y=z;};
int x;
char y;
};
 
class Bar
{
public:
	Base base;
	Bar(int m, char n):base(m,n),q(m),s(n){};
	int q;
	char s;
};
 
int main()
{

	Bar barObj(5,'h');
	cout << barObj.base.x << barObj.base.y << endl;
 
	return 0;
}