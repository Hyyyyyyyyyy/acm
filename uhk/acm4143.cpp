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
const int maxn = 50000 + 100;
const int maxm = 100000 + 100;
ll N;
int main()
{
	ll i, j, cas, CAS;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			ll res = INF;
			for (i = 1; i*i <= N; i++)
			{
				ll t = abs(i - N / i);
				if (t == 0)
					continue;
				if (N % i == 0 && t % 2 == 0)
				{
					if (res > t / 2)
						res = t / 2;
				}
			}
			if (res == INF)
				printf("-1\n");
			else
				printf("%lld\n", res);
		}
	}
	return 0;
}