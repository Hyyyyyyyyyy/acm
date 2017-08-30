#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e18;
const int maxn = 1000 + 100;
const ll MAX = 40000;
int main()
{
	ll i, j, k, n, m, Xa, Xb, Ya, Yb, b, a;
	while (scanf("%lld %lld", &a, &b) != EOF)
	{
		ll Ma = ceil(sqrt(a));
		ll Mb = ceil(sqrt(b));
		if ((Ma*Ma) % 2 != 0)
		{
			ll bx = -((Ma - 1) / 2);
			ll by = bx;
			ll cnt = 1;
			for (i = Ma*Ma; i != a; i--)
			{
				cnt++;
				if (cnt > Ma)
				{
					by += 1;
				}
				else
				{
					bx += 1;
				}
			}
			Xa = bx;
			Ya = by;
		}
		else
		{
			ll bx = (Ma / 2 - 1);
			ll by = bx + 1;
			ll cnt = 1;
			for (i = Ma*Ma; i != a; i--)
			{
				cnt++;
				if (cnt > Ma)
				{
					by -= 1;
				}
				else
				{
					bx -= 1;
				}
			}
			Xa = bx;
			Ya = by;
		}
		if ((Mb*Mb) % 2 != 0)
		{
			ll bx = -((Mb - 1) / 2);
			ll by = bx;
			ll cnt = 1;
			for (i = Mb*Mb; i != b; i--)
			{
				cnt++;
				if (cnt > Mb)
				{
					by += 1;
				}
				else
				{
					bx += 1;
				}
			}
			Xb = bx;
			Yb = by;
		}
		else
		{
			ll bx = (Mb / 2 - 1);
			ll by = bx + 1;
			ll cnt = 1;
			for (i = Mb*Mb; i != b; i--)
			{
				cnt++;
				if (cnt > Mb)
				{
					by -= 1;
				}
				else
				{
					bx -= 1;
				}
			}
			Xb = bx;
			Yb = by;
		}
		ll res = 0;
		if (Xa - Xb < 0)
			res += Xb - Xa;
		else
			res += Xa - Xb;
		if (Ya - Yb < 0)
			res += Yb - Ya;
		else
			res += Ya - Yb;
		printf("%lld\n", res);
	}
	return 0;
}