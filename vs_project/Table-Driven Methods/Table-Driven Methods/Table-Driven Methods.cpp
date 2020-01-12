#include <iostream>

# define MAX_AGE 200
# define MAX_AGE_INDEX 6
# define MAX_Gendar 2
# define MAX_MaritalStatus 3

// �Ա�
enum Gendar
{
	GendarMale = 0,
	GendarFemal = 1
}gemdar;

// ����״��
enum MaritalStatus
{
	MaritalStatusSingle = 0,
	MaritalStatusMarried = 1,
	MaritalStatusdivorce = 2
}maritalStatus;

int ns[3][4][2] = {	
	{ 1, 2, 3, 4 },
	{ 5, 6, 7, 8 },
	{ 9, 10, 11, 12 }
};

// ע���ʼ��Ҫ�ȴ�����Χ��ʼ��
int a[2][3][4] = {
	{
		{1,2,3,4},
		{1,2,3,4},
		{1,2,3,4}
	},
	{
		{5,6,7,8},
		{5,6,7,8},
		{5,6,7,8}
	}
};



// ����˰�ʱ� MAX_AGE������������ֵ
double rateTable[MAX_Gendar][MAX_MaritalStatus][MAX_AGE_INDEX] = {
	{
		{1,2,3,4,5,6},
		{7,8,9,10,11,12},
		{13,14,15,16,17,18}
	},
	{
		{19,20,21,22,23,24},
		{25,26,27,28,29,30},
		{31,32,33,34,35,36}
	}
};

// �������Ϣ
int ageIndex[MAX_AGE_INDEX] = { 0, 20, 50, 60, 70, 80 };

// ��ʵ������ת��Ϊһ������ε�ʵ��
int getAgeIndex(int age)
{
	int iPos=0;
	while (ageIndex[iPos] < age) ++iPos;
	return iPos-1 ;
}

// �м�㣬��ʵ������ת��Ϊһ�������
double getRate(Gendar gemdar, MaritalStatus maritalStatus, int age)
{
	int ageIndex = getAgeIndex(age);
	return rateTable[gemdar][maritalStatus][ageIndex];
}


int main() {
	int age;
	std::cin >> age;

	enum Gendar gemdar = GendarMale;
	enum MaritalStatus maritalStatus = MaritalStatusMarried;

	std::cout << getRate(gemdar, maritalStatus, age) << std::endl;

	return 0;
}

