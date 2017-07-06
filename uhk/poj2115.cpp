#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll A, B, C, K;
ll exGcd(ll a, ll b, ll &x, ll &y)
{
	ll res, temp;
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	res = exGcd(b, a%b, x, y);
	temp = x;
	x = y;
	y = temp - a / b*y;
	return res;
}
int main()
{
	ll i, j, k;
	while (scanf("%lld %lld %lld %lld", &A, &B, &C, &K) != EOF && (A || B || C || K))
	{
		ll x, y;
		ll M = 1ll << K;
		ll res = exGcd(C, M, x, y);
		if ((B - A) % res != 0)
		{
			printf("FOREVER\n");
		}
		else
		{
			x = (x * ((B - A) / res)) % M;          // ax + by = gcd(a, b)  而 这里需要 = B-A，所以x要乘一个系数
			printf("%lld\n", (x % (M/res) + (M/res)) % (M/res));
		}
	}
	return 0;
}