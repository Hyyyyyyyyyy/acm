#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 100000007ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
ll gcd(ll x, ll y)
{
	ll t;
	while (y)
	{
		t = x % y;
		x = y;
		y = t;
	}
	return  x;
}
ll LCM(ll a, ll b)
{
	return a / gcd(a, b) * b;
}
int main()
{
	ll i, j, k, n, m, N, M, CAS, cas, ans, s1, v1, s2, v2;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld %lld %lld %lld", &N, &s1, &v1, &s2, &v2);
			ll lcm = LCM(s1, s2);
			ll num = N / lcm;
			if (num >= 1)
				num--;
			if (v1*s2 >= v2 * s1)  //1性价比高
			{
				num = lcm / s1 * num;   //共多少个1
				ll num2 = (N - num * s1) / s2;
				ans = num * v1 + num2 * v2;
				if (s1 >= s2)
				{
					for (i = num+1; i*s1 <= N; i++)
					{
						ll t = i * v1 + (N - i * s1) / s2 * v2;
						if (t > ans)
							ans = t;
					}
				}
				else
				{
					for (i = num2; i >= 0; i--)
					{
						ll t = i * v2 + (N - i * s2) / s1 * v1;
						if (t > ans)
							ans = t;
					}
				}
			}
			else    //2性价比高
			{
				num = lcm / s2 * num;   //共多少个2
				ll num1 = (N - num * s2) / s1;
				ans = num * v2 + num1 * v1;
				if (s1 >= s2)
				{
					for (i = num1; i >= 0; i--)
					{
						ll t = i * v1 + (N - i * s1) / s2 * v2;
						if (ans < t)
							ans = t;
					}

				}
				else
				{
					for (i = num+1; i*s2 <= N; i++)
					{
						ll t = i * v2 + (N - i * s2) / s1 * v1;
						if (ans < t)
							ans = t;
					}
				}
			}
			printf("Case #%lld: %lld\n", cas, ans);
		}
	}
	return 0;
}