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
const ll MOD = 100000007ll;
const int maxn = 262144 + 100;
const int maxm = 9000000 + 100;
struct Node
{
	ll l;
	ll r;
	ll mid;
	ll num;
};
Node G[maxn * 4];
ll N, K;
void pushup(ll root)
{
	G[root].num = G[root * 2].num + G[root * 2 + 1].num;
}
void build(ll root, ll begin, ll end)
{
	G[root].l = begin;
	G[root].r = end;
	G[root].mid = (begin + end) / 2;
	if (begin == end)
	{
		G[root].num = 1;
		return;
	}
	build(root * 2, G[root].l, G[root].mid);
	build(root * 2 + 1, G[root].mid + 1, G[root].r);
	pushup(root);
}
void update(ll root, ll k)
{
	if (G[root].l == G[root].r)
	{
		G[root].num--;
		return;
	}
	if (k <= G[root * 2].num)
	{
		update(root * 2, k);
	}
	else
	{
		update(root * 2 + 1, k - G[root * 2].num);
	}
	pushup(root);
}
ll query(ll root, ll k)
{
	if (G[root].l == G[root].r)
	{
		return G[root].r;
	}
	if (k <= G[root * 2].num)
	{
		return query(root * 2, k);
	}
	else
	{
		return query(root * 2 + 1, k - G[root * 2].num);
	}
}
int main()
{
	ll i, j, k, CAS, cas, res, a;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld", &N, &K);
			build(1, 1, N);
			res = 0;
			for (i = 1; i <= K; i++)
			{
				scanf("%lld", &a);
				res += query(1, a);
				update(1, a);
			}
			printf("Case %lld: %lld\n", cas, res);
		}
	}
	return 0;
}