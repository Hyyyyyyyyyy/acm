#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
class Date
{
	int year;
	int month;
	int day;
public:
	Date() {}
	Date(int y, int m, int d) : year(y), month(m), day(d) {}
	Date(Date &q)
	{
		year = q.year;
		month = q.month;
		day = q.day;
	}
	void getDate();
	void showDate()
	{
		cout << "year: " << year << "  month: " << month << "  day: " << day << endl;
	}
	friend int Span(Date &d1, Date &d2);
	~Date() {}
};

void Date::getDate()
{
	cout << "Please input your favourite date: (year month day like: XXXX XX XX)" << endl;
	cin >> year >> month >> day;
	cout << "Perfect!\n";
}
bool isleapyear(int a)
{
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		return true;
	else
		return false;
}

int Span(Date &d1, Date &d2)
{
	int count = 0, sum = 0, i;
	int leap_month_day[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };
	int month_day[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	Date temp_d;
	if (d1.year > d2.year)
	{
		temp_d = d1;
		d1 = d2;
		d2 = temp_d;
	}
	for (i = d1.year; i < d2.year; i++)
	{
		if (isleapyear(i))
			count++;
	}
	sum += 365 * (d2.year - d1.year) + count;

	if (isleapyear(d2.year))
		sum += leap_month_day[d2.month - 1] + d2.day;
	else
		sum += month_day[d2.month - 1] + d2.day;
	if (isleapyear(d1.year))
		sum -= leap_month_day[d1.month - 1] + d1.day;
	else
		sum -= month_day[d1.month - 1] + d1.day;

	return sum;
}

int main()
{
	Date date1, date2;
	string s;
	cout << "Please input some dates: (\'no\' to quit)\n";
	while (1)
	{
		cout << "Would you like to continue?(yes/no)";
		cin >> s;
		if (s == "no")
			break;
		date1.getDate();
		date2.getDate();
		date1.showDate();
		date2.showDate();
		cout << "Let's see how many days between them: " << Span(date1, date2) << " days" << endl << endl;
	}
	return 0;
}
