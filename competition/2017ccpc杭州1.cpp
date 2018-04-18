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
#include <stack>
#include <deque>
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
const ll MOD = 998244353ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
struct Node
{
	ll l;
	ll r;
	ll mid;
	ll visit2;
	ll visit3;
	ll num2;
	ll num3;
	ll gcd;
};
Node G[maxn * 4];
ll N, M;
void pushup(ll root)
{
	G[root].num2 = min(G[root * 2].num2, G[root * 2 + 1].num2);
	G[root].num3 = min(G[root * 2].num3, G[root * 2 + 1].num3);
}
void pushdown(ll root)
{
	if (G[root].visit2)
	{
		G[root * 2].num2 += G[root].visit2;
		G[root * 2].visit2 += G[root].visit2;
		G[root * 2 + 1].num2 += G[root].visit2;
		G[root * 2 + 1].visit2 += G[root].visit2;
		G[root].visit2 = 0;
	}
	if (G[root].visit3)
	{
		G[root * 2].num3 += G[root].visit3;
		G[root * 2].visit3 += G[root].visit3;
		G[root * 2 + 1].num3 += G[root].visit3;
		G[root * 2 + 1].visit3 += G[root].visit3;
		G[root].visit3 = 0;
	}
}
void build(ll root, ll begin, ll end)
{
	G[root].l = begin;
	G[root].r = end;
	G[root].mid = (begin + end) / 2;
	G[root].visit2 = 0;
	G[root].visit3 = 0;
	G[root].num2 = 0;
	G[root].num3 = 0;
	G[root].gcd = 1;
	if (begin == end)
	{
		return;
	}
	build(root * 2, G[root].l, G[root].mid);
	build(root * 2 + 1, G[root].mid + 1, G[root].r);
}
void update(ll root, ll b, ll e, ll val)
{
	if (b <= G[root].l && G[root].r <= e)
	{
		if (val == 2)
		{
			G[root].num2++;
			G[root].visit2++;
		}
		else
		{
			G[root].num3++;
			G[root].visit3++;
		}
		return;
	}
	pushdown(root);
	if (b <= G[root].mid)
		update(root * 2, b, e, val);
	if (e > G[root].mid)
		update(root * 2 + 1, b, e, val);
	pushup(root);
}
ll C2[maxn];
ll C3[maxn];
int main()
{
	ll i, j, k, a, b, c, CAS, cas;
	C2[0] = C3[0] = 1;
	C2[1] = 2;
	C3[1] = 3;
	for (i = 2; i <= 100000; i++)
	{
		C2[i] = (C2[i - 1] * 2) % MOD;
		C3[i] = (C3[i - 1] * 3) % MOD;
	}
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld", &N, &M);
			build(1, 1, N);
			for (i = 1; i <= M; i++)
			{
				scanf("%lld %lld %lld", &a, &b, &c);
				update(1, a, b, c);
			}
			printf("%lld\n", (C2[G[1].num2] * C3[G[1].num3]) % MOD);
		}
	}
	return 0;
}