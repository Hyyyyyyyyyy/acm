#include <cstdio>
#include <cstring>
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
const int inf = (1ll << 31) - 1;
const ll INF = (1ull << 63) - 1;
const double eps = 1e-7;
const ll MOD = 1e9;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
struct Node
{
	ll l;
	ll r;
	ll mid;
	ll sum;
};
Node G[maxn*4];
bool limit[maxn*4];
ll N, M;
ll ar[maxn];
void pushup(ll root)
{
	G[root].sum = G[root * 2].sum + G[root * 2 + 1].sum;
	if (limit[root * 2] && limit[root * 2 + 1])
		limit[root] = true;
}
void build(ll root, ll begin, ll end)
{
	G[root].l = begin;
	G[root].r = end;
	G[root].mid = (begin + end) / 2;
	if (begin == end)
	{
		G[root].sum = ar[begin];
		return;
	}
	build(root * 2, G[root].l, G[root].mid);
	build(root * 2 + 1, G[root].mid + 1, G[root].r);
	pushup(root);
}
void update(ll root, ll b, ll e)
{
	if (G[root].l == G[root].r)
	{
		G[root].sum = (ll)sqrt((double)G[root].sum);
		if (G[root].sum <= 1)
			limit[root] = true;
		return;
	}
	if (b <= G[root].mid && !limit[root * 2])
		update(root * 2, b, e);
	if (e > G[root].mid && !limit[root * 2 + 1])
		update(root * 2 + 1, b, e);
	pushup(root);
}
ll query(ll root, ll b, ll e)
{
	if (b <= G[root].l && G[root].r <= e)
	{
		return G[root].sum;
	}
	ll res = 0;
	if (b <= G[root].mid)
		res += query(root * 2, b, e);
	if (e > G[root].mid)
		res += query(root * 2 + 1, b, e);
	return res;
}
int main()
{
	ll i, j, k, a, b, c, n, m, cas = 1;
	while (scanf("%lld", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
			scanf("%lld", &ar[i]);
		build(1, 1, N);
		memset(limit, false, sizeof(limit));
		scanf("%lld", &M);
		printf("Case #%lld:\n", cas++);
		for (i = 1; i <= M; i++)
		{
			scanf("%lld %lld %lld", &a, &b, &c);
			if (b > c)
				swap(b, c);
			if (a == 0)
			{
				update(1, b, c);
			}
			else
			{
				printf("%lld\n", query(1, b, c));
			}
		}
		putchar('\n');
	}
	return 0;
}