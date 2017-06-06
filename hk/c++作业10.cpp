#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
template<class T>
class node
{
public:
	node<T> *next;
	T data;
	node(const T& d, node<T>* n)
	{
		if (n == NULL)
		{
			data = d;
			next = NULL;
		}
		else
		{
			data = d;
			next = n;
		}
	}
	void insertafter(node<T>* p);
	node<T>* deleteafter();
	node<T>* nextnode();
	const node<T>* nextnode() const;
};

template<class T>
node<T>* node<T>::nextnode()
{
	return next;
}
template<class T>
const node<T>* node<T>::nextnode() const
{
	return next;
}
template<class T>
void node<T>::insertafter(node<T>* p)
{
	p->next = next;
	next = p;
}
template<class T>
node<T>* node<T>::deleteafter()
{
	node<T>* t = next;
	if (next == NULL)
		return 0;
	next = t->next;
	return t;
}
template<class T>
class link
{
private:
	node<T> *front, *rear;
	node<T> *pre, *cur;
	int size;
	int pos;
	void freenode(node<T> * p)
	{
		delete p;
	}
public:
	link()
	{
		front = new node<T>(0, NULL);
		rear = front;
		pre = NULL;
		cur = front;
		pos = 0;
		size = 0;
	}
	link(const link<T>& L)
	{
		node<T>* temp = L.front;
		front = new node<T>(0, NULL);
		cur = front;
		while (temp != L.rear)
		{
			temp = temp->next;
			cur->next = new node<T>(temp->data, NULL);
			cur = cur->next;
		}
		rear = cur;
		size = L.size;
		pos = L.pos;
	}
	~link()
	{
		clear();
	}
	link<T>& operator = (const link<T>& L)
	{
		copy(L);
	}
	int getSize() const
	{
		return size;
	}
	bool isEmpty() const
	{
		return (size == 0 ? true : false);
	}
	void reset(int pos = 0)
	{
		pos = 0;
		cur = front;
	}
	void next()
	{
		int i = 0;
		cur = front;
		while (i != pos)
		{
			cur = cur->next;
			i++;
		}
		pos++;
		cur = cur->next;
	}
	bool endOflist() const
	{
		return (pos == size ? true : false);
	}
	int currentPosition() const
	{
		return pos;
	}
	void insertfront(const T& iteam)
	{
		node<T>* t = new node<T>(iteam, front->next);
		front = new node<T>(0, NULL);
		front->next = t;
		rear = t;
		size++;
		pos++;
	}
	void insertrear(const T& iteam)
	{
		node<T>* t = new node<T>(iteam, NULL);
		if (front->next == NULL)
			front->next = t;
		rear->next = t;
		rear = rear->next;
		size++;
	}
	void insertAt(const T& iteam)
	{
		int i = 0;
		cur = front;
		while (i != pos - 1)
		{
			cur = cur->next;
			i++;
		}
		cur->next = new node<T>(iteam, cur->next);
		if (++i <= pos)
			pos++;
		size++;
	}
	void insertAfter(const T& iteam)
	{
		int i = 0;
		cur = front;
		while (i != pos)
		{
			cur = cur->next;
			i++;
		}
		cur->next = new node<T>(iteam, cur->next);
		if (pos >= ++i)
			pos++;
		size++;
	}
	T& deleteFront()
	{
		node<T>* temp = front;
		front = front->next;
		delete temp;
		pos--;
		size--;
	}
	void deleteCurrent()
	{
		int i = 0;
		cur = front;
		while (i != pos - 1)
		{
			cur = cur->next;
			i++;
		}
		node<T>* temp = cur->next;
		cur->next = cur->next->next;
		delete temp;
		if (pos >= ++i)
			pos--;
		size--;
	}
	T& data()
	{
		int i = 0;
		cur = front;
		while (i != pos)
		{
			cur = cur->next;
			i++;
		}
		return cur->data;
	}
	void clear()
	{
		while (front != rear)
		{
			node<T> *temp = front;
			front = front->next;
			freenode(temp);
		}
		freenode(rear);
		pos = size = 0;
	}
	void show()
	{
		if (size == 0)
			return;
		cur = front;
		while (cur != rear)
		{
			cur = cur->next;
			cout << cur->data << "  ";
		}
		cout << endl;
	}
};
int main()
{
	link<int>G;
	G.insertfront(1);
	G.insertrear(2);
	G.insertrear(3);
	G.show();
	link<int>F(G);
	F.show();
	cout << "G.size = " << G.getSize() << endl;
	cout << "F.size = " << F.getSize() << endl;
	cout << "G.isEmpty " << endl;
	if (!G.isEmpty())
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	G.reset();
	cout << "G.currentPosition() = " << G.currentPosition() << "  " << "G.data() = " << G.data() << endl;
	G.next();
	cout << "G.currentPosition() = " << G.currentPosition() << "  " << "G.data() = " << G.data() << endl;
	G.insertAt(4);
	G.insertAfter(5);
	G.show();
	G.insertAt(6);
	G.insertAfter(7);
	G.show();
	return 0;
}
