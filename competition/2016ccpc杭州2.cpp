#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 2147483647;
const ll INF = 9223372036854775800;
const double eps = 1e-8;
const int maxn = 100000 + 100;
char s[100];
ll change(ll begin, ll len)
{
	ll res = 0;
	for (ll i = begin; i < begin + len; i++)
	{
		res = res * 10 + s[i] - '0';
	}
	return res;
}
int main()
{
	ll i, j, k, n, m;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%s", s);
			printf("Case #%lld: ", m);
			ll L = strlen(s);
			ll A, B, C, D, E;
			ll res = -INF;
			for (i = L - 1; i >= 4; i--)
			{
					E = change(i, L - i);
					D = change(i - 1, 1);
					C = change(i - 2, 1);
					B = change(i - 3, 1);
					A = change(0, i - 3);
					ll t = A + B - C * D / E;
					if (res < t)
						res = t;
					E = change(i, L - i);
					D = change(i - 1, 1);
					C = change(i - 2, 1);
					B = change(1, i - 3);
					A = change(0, 1);
					t = A + B - C * D / E;
					if (res < t)
						res = t;
				ll T = L - i - 2;
				if (T % 2 == 1)
				{
					E = change(i, L - i);
					D = change(i - 1, 1);
					C = change(i - 2, 1);
					B = change(T/2ll, T/2ll+1ll);
					A = change(0, T / 2ll);
					t = A + B - C * D / E;
					if (res < t)
						res = t;
					E = change(i, L - i);
					D = change(i - 1, 1);
					C = change(i - 2, 1);
					B = change(T / 2ll+1, T / 2ll);
					A = change(0, T / 2ll+1);
					t = A + B - C * D / E;
					if (res < t)
						res = t;
				}
				else
				{
					E = change(i, L - i);
					D = change(i - 1, 1);
					C = change(i - 2, 1);
					B = change(T / 2ll, T / 2ll);
					A = change(0, T / 2ll);
					ll t = A + B - C * D / E;
					if (res < t)
						res = t;
				}
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}