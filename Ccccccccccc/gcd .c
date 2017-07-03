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
ll exGcd(ll a, ll b, ll &x, ll &y)
{
    ll res, temp;
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
typedef long long ll;
const int maxn = 20;
using namespace std;
ll A[maxn], M[maxn];
void extend_Euclid(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	extend_Euclid(b, a % b, x, y);
	ll tmp = x;
	x = y;
	y = tmp - (a / b) * y;
}
ll CRT(ll n)
{
	ll ans = 0;
	ll MM = 1;
	for (ll i = 1; i <= n; i++)
		MM *= M[i];
	for (ll i = 1; i <= n; i++)
	{
		ll x, y;
		ll Mi = MM / M[i];
		extend_Euclid(Mi, M[i], x, y);
		ans = (ans + Mi * x * A[i]) % MM;
	}
	if (ans < 0) ans += MM;
	return ans;
}


//中国剩余定理 非互质模板；
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int ll;
const int maxn = 15;
ll M;

ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

ll Extend_Euclid(ll a, ll b, ll&x, ll& y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	ll d = Extend_Euclid(b, a%b, x, y);
	ll t = x;
	x = y;
	y = t - a / b*y;
	return d;
}

//a在模n乘法下的逆元，没有则返回-1
ll inv(ll a, ll n)
{
	ll x, y;
	ll t = Extend_Euclid(a, n, x, y);
	if (t != 1)
		return -1;
	return (x%n + n) % n;
}

//将两个方程合并为一个
bool merge(ll a1, ll n1, ll a2, ll n2, ll& a3, ll& n3)
{
	ll d = gcd(n1, n2);
	ll c = a2 - a1;
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
ll China_Reminder2(int len, ll* a, ll* n)
{
	ll a1 = a[0], n1 = n[0];
	ll a2, n2;
	for (int i = 1; i < len; i++)
	{
		ll aa, nn;
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
    ll a[N], m[N], res;
}