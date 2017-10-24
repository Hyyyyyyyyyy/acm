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
const ll MOD = 1e9 + 7;
const int maxn = 600000 + 100;
multiset<ll>G;
struct Node
{
	ll b;
	ll e;
};
Node ar[maxn];
bool comp(const Node& a, const Node& b)
{
	if (a.b != b.b)
		return a.b < b.b;
	else
		return a.e < b.e;
}
int main()
{
	ll i, j, k, u, n, m, a, b, cnt, N, M;
	while (scanf("%lld %lld", &N, &M) != EOF)
	{
		cnt = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%lld %lld", &a, &b);
			ar[++cnt].b = a;
			ar[cnt].e = a + b;
		}
		sort(ar + 1, ar + 1 + cnt, comp);
		ll flag = -INF;
		ll res = 0;
		G.clear();
		for (i = 1; i <= cnt; i++)
		{
			if (!G.empty())
			{
				multiset<ll>::iterator pos = G.lower_bound(ar[i].b - M);		//没有间隔M时间以内的限制    改为0即可
				if (pos != G.end())
				{
					ll t = *pos;
					if (t <= ar[i].b)
					{
						G.erase(pos);
						res++;
					}
				}
			}
			G.insert(ar[i].e);
		}
		printf("%lld\n", res);		//res为可以合并的区间数
	}
	return 0;
}