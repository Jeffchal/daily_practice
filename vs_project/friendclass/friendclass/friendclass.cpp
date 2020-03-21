//#include <iostream>
//
//using namespace std;
//
//class A;    //���õ���Ԫ��Ա����ʱ����ע����Ԫ��������Ԫ����֮��Ļ���������������A������
//
//class B
//{
//public:
//    void set_show(int x, A &a);             //�ú�������A����Ԫ����
//};
//
//class A
//{
//public:
//    friend void B::set_show(int x, A &a);   //�ú�������Ԫ��Ա����������
//private:
//    int data;
//    void show() { cout << data << endl; }
//};
//
//
//void B::set_show(int x, A &a)       //ֻ���ڶ�����A����ܶ���ú������Ͼ���������Ϊ��Ԫ��Ϊ�˷�����A�ĳ�Ա
//{
//    a.data = x;
//    cout << a.data << endl;
//}
//
//int main(void)
//{
//    class A a;
//    class B b;
//
//    b.set_show(1, a);
//
//    return 0;
//}


#include <iostream>

using namespace std;

class Box
{
	double width;
public:
	void printWidth();
	friend void printWidth1(Box box);
	void setWidth(double wid);
	Box() : width(10) {};
};

// ��Ա��������
void Box::setWidth(double wid)
{
	width = wid;
}


void  Box::printWidth()
{
	/* ��Ϊ printWidth() �� Box ����Ԫ��������ֱ�ӷ��ʸ�����κγ�Ա */
	cout << "Width of box : " << width << endl;
}
// ��ע�⣺printWidth1() �����κ���ĳ�Ա����
void  printWidth1(Box box)
{
	/* ��Ϊ printWidth() �� Box ����Ԫ��������ֱ�ӷ��ʸ�����κγ�Ա */
	cout << "Width of box : " << box.width << endl;
}

// �����������
int main()
{
	Box boxfox;
	Box boxfxk;
	// ʹ�ó�Ա�������ÿ��
	boxfox.setWidth(20.0);

	// ʹ����Ԫ����������
	boxfox.printWidth();

	printWidth1(boxfox);
	printWidth1(boxfxk);
	return 0;
}