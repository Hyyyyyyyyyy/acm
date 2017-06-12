#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
class overrange
{
public:
	overrange() {}
	~overrange() {}
};
class donotfind
{
public:
	donotfind() {}
	~donotfind() {}
};

template<class T>
class Set
{
public:
	Set() {}
	Set<T>(T* q, int n)
	{
		int i, j, cnt = 0;
		P = new T[n + 1];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < cnt; j++)
			{
				if (q[i] == P[j])
					break;
			}
			if (j == cnt)
				P[cnt++] = q[i];
		}
		size = cnt;
	}
	Set<T>(T a, int n) : size(n)
	{
		P = new T[1];
		P[0] = a;
	}
	Set<T>(int n) : size(n)
	{
		P = new T[size + 1];
	}
	Set<T>(const Set<T>& q)
	{
		size = q.size;
		P = new T[size + 1];
		for (int i = 0; i < size; i++)
			P[i] = q.P[i];
	}
	void Add(int n)
	{
		T* t = new T[size + 1];
		for (int i = 0; i < size; i++)
			t[i] = P[i];
		delete[] P;
		P = new T[n + 1];
		for (int i = 0; i < size; i++)
			P[i] = t[i];
	}
	void show()
	{
		cout << "size = " << size << "  ";
		cout << "{ ";
		for (int i = 0; i < size; i++)
		{
			if (i != 0)
				cout << ", ";
			cout << P[i];
		}
		cout << " }" << endl;
	}
	void insert(T a, int n)
	{
		if (n < 0)
			n == 0;
		if (n > size)
			n = size;
		for (int i = 0; i < size; i++)
			if (P[i] == a)
				return;
		Add(size + 1);
		for (int i = size - 1; i >= n - 1; i--)
			P[i + 1] = P[i];
		P[n - 1] = a;
		size++;
	}
	virtual void insert(T a)
	{
		for (int i = 0; i < size; i++)
			if (P[i] == a)
				return;
		Add(size + 1);
		P[size] = a;
		size++;
	}

	virtual void del(T a)
	{
		for (int i = 0; i < size; i++)
			if (P[i] == a)
			{
				for (int j = i; j < size - 1; j++)
				{
					P[j] = P[j + 1];
				}
				size--;
				return;
			}
		throw donotfind();
	}
	T& operator [] (int i)
	{
		return P[i];
	}
	virtual Set<T> operator && (Set<T>& q)
	{
		Set<T>t(min(size, q.size));
		int cnt = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < q.size; j++)
			{
				if (P[i] == q[i])
				{
					t[cnt++] = P[i];
					break;
				}
			}
		}
		t.size = cnt;
		return t;
	}
	virtual Set<T> operator || (Set<T>& q)
	{
		int i, j;
		Set<T>t(q);
		int cnt = t.size;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < t.size; j++)
			{
				if (P[i] == t[j])
					break;
			}
			if (j == t.size)
				t[cnt++] = P[i];
		}
		t.size = cnt;
		return t;
	}
	bool Belong(Set<T>& q)
	{
		int i, j;
		if (size > q.size)
			return false;
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < q.size; j++)
			{
				if (P[i] == q[j])
					break;
			}
			if (j == q.size)
				return false;
		}
		return true;
	}
	bool operator == (Set<T>& q)
	{
		if (Belong(q) && q.Belong(Set<T>(P, size)))
			return true;
		else
			return false;
	}
protected:
	T* P;
	int size;
};

template<class T>
class SortSet : public Set<T>
{
public:
	SortSet() {}
	SortSet<T>(T* q, int n) : Set<T>(q, n)
	{
		sort(P, P + size);
	}
	SortSet<T>(T a, int n) : Set<T>(a, n) {}
	SortSet<T>(int n) : Set<T>(n) {}
	SortSet<T>(const SortSet<T>& q) : Set<T>(q)
	{
		sort(P, P + size, comp);
	}
	virtual SortSet<T> operator || (SortSet<T>& q)
	{
		int i, j;
		T* t = new T[size + q.size+1];
		for (i = 0; i < size; i++)
		{
			t[i] = P[i];
		}
		int cnt = size;
		for (i = 0; i < q.size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (q[i] == P[j])
					break;
			}
			if (j == size)
				t[cnt++] = q[i];
		}
		sort(t, t + cnt - 1);
		return SortSet<T>(t, cnt - 1);
	}
	virtual SortSet<T> operator && (SortSet<T>& q)
	{
		int i, j;
		T* t = new T[size + q.size + 1];
		int cnt = 0;
		for (i = 0; i < q.size; i++)
		{
			for (j = 0; j < size; j++)
			{
				if (q[i] == P[j])
					break;
			}
			if (j != size)
				t[cnt++] = q[i];
		}
		sort(t, t + cnt - 1);
		return SortSet<T>(t, cnt - 1);
	}
	virtual void del(T a)
	{
		int l = 0;
		int r = size;
		int mid;
		while (r >= l)
		{
			mid = (r + l) / 2;
			if (P[mid] < a)
				l = mid + 1;
			else if (P[mid] > a)
				r = mid - 1;
			else
				break;
		}
		if (P[mid] == a)
		{
			for (int i = mid; i < size; i++)
				P[i] = P[i + 1];
			size--;
		}
		else
			throw donotfind();
		return;
	}
	virtual void insert(T a)
	{
		Add(size + 10);
		int l = 0;
		int r = size;
		int mid;
		while (r >= l)
		{
			mid = (l + r) / 2;
			if (P[mid] >= a)
				r = mid - 1;
			else
				l = mid + 1;
		}
		for (int i = size + 1; i > l; i--)
		{
			P[i] = P[i - 1];
		}
		if (P[l] != a || l > size)
		{
			P[l] = a;
			size++;
		}
		else
			throw overrange();
		return;
	}
};

int main()
{
	try
	{
		int t1[] = { 3, 6, 4, 1, 1, 1, 2, 5, 5 };
		int t2[] = { 3, 6, 4, 1, 1, 1, 2, 5, 5 };
		Set<int>a(t1, 9);
		SortSet<int>b(t2, 9);
		b.del(3);
		b.del(4);
		b.show();
		b.insert(3);
		b.show();
		//b.insert(1);
		b.insert(4);
		//a.show();
		b.show();
	}
	catch (overrange)
	{
		cout << "overrange\n";
	}
	catch (donotfind)
	{
		cout << "donotfind\n";
	}
	catch (...)
	{
		cout << "failed\n";
	}
	return 0;
}