//朴素欧几里得 非递归
int gcd(int x,int y)
{
    int t;
    while(y)
    {
        t=x%y;
        x=y;
        y=t;
    }
    return  x;
}
最小公倍数 = x * y / gcd(x, y);
//朴素欧几里得 递归
int gcd(int a,int b)
{
    return b ? gcd(b, a%b):a;
}

//扩展欧几里得
int exGcd(int a, int b, int &x, int &y)
{
    int res, temp;
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    res = exGcd(b, a%b, x, y);
    temp = x;
    x = y;
    y = temp-a/b*y;
    return res;
}
/*
int gcd(int a, int b, int &x, int &y)
{
    if (b==0)
    {
        x=1；
        y=0;
        return a;
    }
    int q=gcd(b, a%b, y, x);
    y -= a/b*x;
    return q;
}
*/

//a[] 是余数， m[]是除数，M是总乘数，Mi是去掉m[i]的乘数， x, y是扩展欧几里得的系数，ans是结果；
//中国剩余定理 互质模板；
#include<iostream>
#include<cstdio>
#include<cstring>
typedef long long LL;
const int N = 1000;
using namespace std;
LL M ;
void extend_Euclid(LL a, LL b, LL &x, LL &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	extend_Euclid(b, a % b, x, y);
	LL tmp = x;
	x = y;
	y = tmp - (a / b) * y;
}
LL CRT(LL a[],LL m[],LL n)
{
    LL ans = 0;
    for(int i=1; i<=n; i++)
        M *= m[i];
    for(int i=1; i<=n; i++)
    {
        LL x, y;
        LL Mi = M / m[i];
        extend_Euclid(Mi, m[i], x, y);
        ans = (ans + Mi * x * a[i]) % M;
    }
    if(ans < 0) ans += M;
    return ans;
}


//中国剩余定理 非互质模板；
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int LL;
const int N = 15;
LL M;

LL gcd(LL a, LL b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

LL Extend_Euclid(LL a, LL b, LL&x, LL& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	LL d = Extend_Euclid(b, a%b, x, y);
	LL t = x;
	x = y;
	y = t - a / b*y;
	return d;
}

//a在模n乘法下的逆元，没有则返回-1
LL inv(LL a, LL n)
{
	LL x, y;
	LL t = Extend_Euclid(a, n, x, y);
	if (t != 1)
		return -1;
	return (x%n + n) % n;
}

//将两个方程合并为一个
bool merge(LL a1, LL n1, LL a2, LL n2, LL& a3, LL& n3)
{
	LL d = gcd(n1, n2);
	LL c = a2 - a1;
	if (c%d)
		return false;
	c = (c%n2 + n2) % n2;
	c /= d;
	n1 /= d;
	n2 /= d;
	c *= inv(n1, n2);
	c %= n2;
	c *= n1*d;
	c += a1;
	n3 = n1*n2*d;
	a3 = (c%n3 + n3) % n3;
	return true;
}

//求模线性方程组x=ai(mod ni),ni可以不互质
LL China_Reminder2(int len, LL* a, LL* n)
{
	LL a1 = a[0], n1 = n[0];
	LL a2, n2;
	for (int i = 1; i < len; i++)
	{
		LL aa, nn;
		a2 = a[i], n2 = n[i];
		if (!merge(a1, n1, a2, n2, aa, nn))
			return -1;
		a1 = aa;
		n1 = nn;
	}
	M = n1;
	return (a1%n1 + n1) % n1;
}

int main()
{
    LL a[N], m[N], res;
}