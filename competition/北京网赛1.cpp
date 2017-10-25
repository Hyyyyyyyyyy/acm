#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 998244353;
const ll maxn = (1 << 19) + 100;
int ar[maxn];
struct Node
{
	int l;
	int r;
	int mid;
	int Min;
	int Max;
	int res;
};
Node G[maxn];
void pushup(int root)
{
	int Min = min(G[root * 2].Min, G[root * 2 + 1].Min);
	int Max = max(G[root * 2].Max, G[root * 2 + 1].Max);
	G[root].Min = Min;
	G[root].Max = Max;
}
void build(int root, int begin, int end)
{
	G[root].l = begin;
	G[root].r = end;
	G[root].mid = (begin + end) / 2;
	if (begin == end)
	{
		G[root].Min = G[root].Max = G[root].res = ar[begin];
		return;
	}
	build(root * 2, begin, G[root].mid);
	build(root * 2 + 1, G[root].mid + 1, end);
	pushup(root);
}
void update(int root, int index, int val)
{
	if (G[root].l == G[root].r && G[root].l == index)
	{
		ar[index] = val;
		G[root].Min = G[root].Max = val;
		G[root].res = val*val;
		return;
	}
	if (index <= G[root].mid)
		update(root * 2, index, val);
	else
		update(root * 2 + 1, index, val);
	pushup(root);
}
int query_min(int root, int b, int e)
{
	if (G[root].l > e || G[root].r < b)
	{
		return INF;
	}
	if (b <= G[root].l && G[root].r <= e)
	{
		return G[root].Min;
	}
	int t1 = INF;
	int t2 = INF;
	if (G[root].mid >= b)
		t1 = query_min(root * 2, b, e);
	if (G[root].mid < e)
		t2 = query_min(root * 2 + 1, b, e);
	return min(t1, t2);
}
int query_max(int root, int b, int e)
{
	if (G[root].l > e || G[root].r < b)
	{
		return -INF;
	}
	if (b <= G[root].l && G[root].r <= e)
	{
		return G[root].Max;
	}
	int t1 = -INF;
	int t2 = -INF;
	if (G[root].mid >= b)
		t1 = query_max(root * 2, b, e);
	if (G[root].mid < e)
		t2 = query_max(root * 2 + 1, b, e);
	return max(t1, t2);
}
int main()
{
	int i, j, k, u, n, m, a, b, c, K, Q;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &K);
			int N = (1 << K);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &ar[i]);
			}
			scanf("%d", &Q);
			build(1, 1, N);
			for (i = 1; i <= Q; i++)
			{
				scanf("%d %d %d", &a, &b, &c);
				if (a == 1)
				{
					b++;
					c++;
					int Max = query_max(1, b, c);
					int Min = query_min(1, b, c);
					ll res;
					if (Min < 0 && Max < 0)
					{
						res = (ll)Max * (ll)Max;
					}
					else if (Max == 0)
					{
						res = 0;
					}
					else if (Min < 0 && Max > 0)
					{
						res = (ll)Min * (ll)Max;
					}
					else if (Min == 0)
					{
						res = 0;
					}
					else if (Min > 0)
					{
						res = (ll)Min * (ll)Min;
					}
					printf("%lld\n", res);
				}
				else
				{
					b++;
					update(1, b, c);
				}
			}
		}
	}
	return 0;
}