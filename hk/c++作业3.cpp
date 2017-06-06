#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Cat
{
	static int numOfCats;
	string name;
public:
	Cat() {}
	Cat(string b) : name(b) {
		numOfCats++;
	}
	Cat(Cat &q) {
		name = q.name;
		numOfCats++;
	}
	void input() {
		numOfCats++;
		cin >> name;
	}
	string getName() {
		return name;
	}
	static int getNumOfCats() {
		return numOfCats;
	}
	void show() {
		cout << name << ": " << numOfCats << endl;
	}
	~Cat() {}
};

int Cat::numOfCats = 0;
int main()
{
	cout << "Give a sample: \n";
	Cat cat1("Kitty");
	cat1.show();
	Cat cat2("Tommy");
	cat2.show();
	Cat cats;
	while (1)
	{
		cout << "Please input your cat's name: (q to quit)" << endl;
		cats.input();
		if (cats.getName() == "q")
			break;
		cats.show();
	}
	return 0;
}
