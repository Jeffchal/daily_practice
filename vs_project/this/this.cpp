// this ָ��ʵ��
#include <iostream>
using namespace std;
class Student {
public:
	void setname(const char *name);
	void setage(int age);
	void setscore(float score);
	void show();
private:
	const char *sname;
	int sage;
	float sscore;
};
void Student::setname(const char *name) {
	this->sname = name;
	sname = name;
}
void Student::setage(int age) {
	this->sage = age;
	sage = age;
}
void Student::setscore(float score) {
	this->sscore = score;
	sscore = score;
}
void Student::show() {
	cout << this->sname << "��������" << this->sage << "���ɼ���" << this->sscore << endl;
	cout << sname << "��������" << sage << "���ɼ���" << sscore << endl;
}
int main() {
	Student *pstu = new Student;
	pstu->setname("�");
	pstu->setage(16);
	pstu->setscore(96.5);
	pstu->show();
	return 0;
}