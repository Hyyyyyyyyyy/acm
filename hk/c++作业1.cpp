#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Birth
{
	int year;
	int month;
	int day;
public:
	Birth() {};
	Birth(int y, int m = 11, int d = 11) : year(y), month(m), day(d) {};
	Birth(Birth &q)
	{
		year = q.year;
		month = q.month;
		day = q.day;
	}
	void play()
	{
		cout << "year: " << year << endl << "month: " << month << endl << "day: " << day << endl;
	}
	void input()
	{
		cin >> year >> month >> day;
	}
	~Birth() {};
};

class Person
{
	int id;
	string sex;
	Birth date;
	long long card;
public:
	Person() {};
	Person(int i, int c, string &s, Birth d) : id(i), card(c), sex(s), date(d) {};

	Person(const Person &p)
	{
		id = p.id;
		card = p.card;
		sex = p.sex;
		date = p.date;
	}

	void show()
	{
		cout << "id: " << id << endl << "card: " << card << endl << "sex: " << sex << endl;
		date.play();
	}
	void insert()
	{
		cout << "Please input the information in the order: (id card sex date(year month day))\n";
		cin >> id >> card >> sex;
		date.input();
	}
	~Person() {};
};


int main()
{
	int i, n, cnt;
	string ar;
	queue<Person>q;
	Person per;
	cout << "Please enter the number of people(0 to quit)\n";
	while (scanf("%d", &n) != EOF && n)
	{
		for (i = 1; i <= n; i++)
		{
			per.insert();
			q.push(per);
		}
		cout << "Would you like to see it ?(yes, no)\n";
		cin >> ar;
		if (ar == "yes")
		{
			cnt = 1;
			while (!q.empty())
			{
				cout << cnt << "、\n";
				per = q.front();
				q.pop();
				per.show();
				cout << "-------------------------------------------------\n\n";
				cnt++;
			}
		}
		else
		{
			while (!q.empty())
				q.pop();
			break;
		}
		cout << "Please enter the number of people again(0 to quit)\n";
	}
	return 0;
}
