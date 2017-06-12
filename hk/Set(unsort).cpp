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
    Set<T>(T* q, int n) : size(n)
    {
        P = new T[size+1];
        for(int i = 0; i < size; i++)
            P[i] = q[i];
    }
    Set<T>(T a, int n) : size(n)
    {
        P = new T[size+1];
        for(int i = 0; i < size; i++)
            P[i] = a;
    }
    Set<T>(int n) : size(n)
    {
        P = new T[size+1];
    }
    Set<T>(const Set<T>& q)
    {
        size = q.size;
        P = new T[size+1];
        for(int i = 0; i < size; i++)
            P[i] = q.P[i];
    }
    void Add(int n)
    {
        T* t = new T[size+1];
        for(int i = 0; i < size; i++)
            t[i] = P[i];
        delete [] P;
        P = new T[n+1];
        for(int i = 0; i < size; i++)
            P[i] = t[i];
    }
    void show()
    {
        cout << "size = " << size << "  ";
        cout << "{ ";
        for(int i = 0; i < size; i++)
            cout << P[i] << ", ";
        cout << " }" << endl;
    }
    void insert(T a, int n)
    {
        if(n < 0)
            n == 0;
        if(n > size)
            n = size;
        for(int i = 0; i < size; i++)
            if(P[i] == a)
                return;
        Add(size+1);
        for(int i = size-1; i >= n-1; i--)
            P[i+1] = P[i];
        P[n-1] = a;
        size++;
    }
    virtual void insert(T a)
    {
        for(int i = 0; i < size; i++)
            if(P[i] == a)
                return;
        Add(size+1);
        P[size] = a;
        size++;
    }
    void del(int n)
    {
        if(n < 0 || n >= size)
            throw overrange();
        for(int i = n-1; i < size-1; i++)
        {
            P[i] = P[i+1];
        }
        size--;
    }
    virtual void del(T a)
    {
        for(int i = 0; i < size; i++)
            if(P[i] == a)
            {
                for(int j = i; j < size-1; j++)
                {
                    P[j] = P[j+1];
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
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < q.size; j++)
            {
                if(P[i] == q[i])
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
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < t.size; j++)
            {
                if(P[i] == t[j])
                    break;
            }
            if(j == t.size)
                t[cnt++] = P[i];
        }
        t.size = cnt;
        return t;
    }
    bool Belong(Set<T>& q)
    {
        int i, j;
        if(size > q.size)
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
        if(Belong(q) && q.Belong(Set<T>(P, size)))
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
    SortSet<T>(T* q, int n) : Set<T>(q, n) {}
    SortSet<T>(int n) : Set<T>(n) {}
    SortSet<T>
}