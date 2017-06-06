#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;
bool Isprime(ll n);
bool IsPn(ll a, ll p, ll mod);
int main()
{
	ll i, j, k, n, m, a, b, p;
	while (scanf("%lld %lld", &p, &a) != EOF && (a || p))
	{
		if (Isprime(p))
		{
			printf("no\n");
		}
		else
		{
			if (IsPn(a, p, p))
				printf("yes\n");
			else
				printf("no\n");
		}
	}
	return 0;
}
bool Isprime(ll n)
{
	int i, j, k;
	for (i = 2; i*i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}
bool IsPn(ll a, ll p, ll mod)
{
	ll res = 1, b = a;
	while (p)
	{
		if (p & 1)
		{
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		p >>= 1;
	}
	res %= mod;
	if (res == b)
		return true;
	return false;
}
