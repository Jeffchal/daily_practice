#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
    cout << "���ù��캯��" << endl;
}

//Date::Date(const Date &date1)
//{
//    year = date1.year;
//    month = date1.month;
//    day = date1.day;
//    cout << "���ÿ������캯��" << endl;
//}

void Date::showDate()
{
    cout << year << "." << month << "." << day << endl;
} 