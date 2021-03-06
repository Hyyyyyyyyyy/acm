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





//费马定理
//a在模n乘法下的逆元
long long MUL(long long a, long long b, long long mod)
{
	long long res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}
long long inv(long long a, long long n)
{
	return MUL(a, n-2, n);
}





#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 10000000;
bool check[maxn + 10];
int prime[maxn + 10];
int phi[maxn + 10];
int tot;
void phi_and_prime_table(int N)
{
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for(int i = 2; i <= N; i++)
    {
        if(!check[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for(int j = 0; j < tot; j++)
        {
            if(i * prime[j] > N)
                break;
            check[i * prime[j]] = true;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}
//质数个数 < tot
//欧拉定理 a在模n乘法下的逆元，n不用是质数
long long inv(long long a, long long n)
{
	return MUL(a, (long long)phi[n]-1, n);
}






//逆元表1~n范围模p(奇质数)乘法下的逆元 o(n)
long long inv[maxn];
void inverse(long long n, long long p) 
{
    inv[1] = 1;  
    for (long long i = 2; i <= n; ++i)
	{
        inv[i] = (p - p / i) * inv[p % i] % p;  
    }
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

//A[] 是余数， M[]是除数，MM是总乘数，Mi是去掉M[i]的乘数， x, y是扩展欧几里得的系数，ans是结果；
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










//A[] 是余数， M[]是除数，S是通解的差， x, y是扩展欧几里得的系数，ans是结果；
//中国剩余定理 非互质模板；
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int ll;
const int maxn = 15;
ll S;
ll A[maxn], M[maxn];

ll gcd(ll x, ll y)
{
	ll t;
	while (y)
	{
		t = x%y;
		x = y;
		y = t;
	}
	return  x;
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
bool merge(ll a1, ll m1, ll a2, ll m2, ll& a3, ll& m3)
{
	ll d = gcd(m1, m2);
	ll c = a2 - a1;
	if (c%d)
		return false;
	c = (c%m2 + m2) % m2;
	c /= d;
	m1 /= d;
	m2 /= d;
	c *= inv(m1, m2);
	c %= m2;
	c *= m1*d;
	c += a1;
	m3 = m1*m2*d;
	a3 = (c%m3 + m3) % m3;
	return true;
}

//求模线性方程组x=ai(mod ni),ni可以不互质
//最小结果（特解）是(a1%n1 + n1) % n1，通解是(a1%n1 + n1) % n1 + K*S，K是倍数
ll China_Reminder2(ll len)
{
	ll a1 = A[1], m1 = M[1];
	ll a2, m2;
	for (ll i = 2; i <= len; i++)
	{
		ll aa, mm;
		a2 = A[i], m2 = M[i];
		if (!merge(a1, m1, a2, m2, aa, mm))
			return -1;
		a1 = aa;
		m1 = mm;
	}
	S = m1;			//S 或者 n1 就是 通解的差
	return (a1 % m1 + m1) % m1;
}

int main()
{
   
}