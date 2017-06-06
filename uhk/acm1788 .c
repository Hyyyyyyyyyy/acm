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
	int i, j, k, u, I;
	LL a[N], m[N], res;
	while (scanf("%d %d", &I, &u) != EOF && (I || u))
	{
		for (i = 0; i < I; i++)
		{
			scanf("%lld", &m[i]);
			a[i] = m[i] - u;
		}
		res = China_Reminder2(I, a, m);
		printf("%lld\n", res);
	}
}
