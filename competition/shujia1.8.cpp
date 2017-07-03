#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef __int64 ll;
const ll maxn = 1e10;
int main()
{
	ll i, j, k, u, n, m, a, b, c, d;
	while (scanf("%I64d\n", &n) != EOF)
	{
		scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
		if (a + b + d >= n)
		{
			printf("%I64d\n", n);
			continue;
		}
		ll x = n - a - b;
		ll t = min(c, d);
		x -= t * 2;
		if (x <= 0)
		{
			printf("%I64d\n", n);
			continue;
		}
		if (c < d)
		{
			d -= c;
			if (x > d)
				x -= d;
			else
				x = 0;
		}
		else
		{
			c -= d;
			if (x % 2 == 0)
			{
				ll tt = x / 2;
				if (tt >= c)
					x -= c;
				else
					x -= tt;
			}
			else
			{
				ll tt = x / 2 + 1;
				if (tt >= c)
					x -= c;
				else
					x -= tt;
			}
		}
		printf("%I64d\n", n-x);
	}
	return 0;
}
