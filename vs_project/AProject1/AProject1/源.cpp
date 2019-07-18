#include<iostream>
using namespace std;

class A
{
public:
	A() { cout << "constructor" << endl; };
	A(int, int) { cout << "int���캯��" << endl; };
	A(const A &) { cout << "copy constructor" << endl; };
	void operator()(int a, int b) { cout << "a+b" << endl; }
	void sum() { cout << "sum����"<<endl; }
};
void set(A visit) {
	visit(1, 2);
}
int main()
{
	//set(A());
	A *b = new A(1, 2);
	A *c = new A;
	A *d = new A();
	
	b->sum();
	c->sum();
	d->sum();

	delete b, c, d;

	return 0;
}

 