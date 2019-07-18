#include <iostream>
using namespace std;
class Base1 {
public:
 Base1(int i)
 { cout << "Constructing Base1 " << i << endl; }
 ~Base1() { cout << "Destructing Base1" << endl; }
};
class Base2 {
public:
 Base2(int j)
 { cout << "Constructing Base2 " << j << endl; }
 ~Base2() { cout << "Destructing Base2" << endl; }
}; 
class Base3 {
public:
 Base3() { cout << "Constructing Base3 *" << endl; }
 ~Base3() { cout << "Destructing Base3" << endl; }
};
class Derived: public Base2, public Base1, public Base3 {
public:
 Derived(int a, int b, int c, int d): Base1(a), member2(d), member1(c),
Base2(b)
 { }
private:
 Base1 member1;
 Base2 member2;
 Base3 member3;
};
int main() {
 Derived obj(1, 2, 3, 4);
 return 0;
} 