#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
    Date(int y, int m, int d);  // ���캯�� 
   // Date(const Date &date1);   // �������캯��                                                                                  
    void showDate();

private:
    int year;
    int month;
    int day;
};


