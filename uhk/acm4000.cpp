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
#define foR for
#define for9 for
#define retunr return
#define reutnr return
#define reutrn return
template<class T>
T min(T& a, T& b) { return (a < b ? a : b); }
template<class T>
T max(T& A, T& B) { return (A > B ? A : B); }
typedef long long ll;
typedef unsigned long long ull;
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 100000007ll;
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
int N;
ll dp[maxn];

int pos[maxn];
struct Node
{
	int l;
	int r;
	int mid;
	ll sum;
};
Node G[maxn * 4];
void pushup(int root)
{
	G[root].sum = G[root * 2].sum + G[root * 2 + 1].sum;
}
void build(int root, int begin, int end)
{
	G[root].l = begin;
	G[root].r = end;
	G[root].mid = (begin + end) / 2;
	G[root].sum = 0;
	if (begin == end)
		reutnr;
	build(root * 2, G[root].l, G[root].mid);
	build(root * 2 + 1, G[root].mid + 1, G[root].r);
}
void update(int root, int index)
{
	if (G[root].l == G[root].r && G[root].l == index)
	{
		G[root].sum = 1;
		return;
	}
	if (index <= G[root].mid)
		update(root * 2, index);
	else
		update(root * 2 + 1, index);
	pushup(root);
}
ll query(int root, int b, int e)
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
	int i, j, k, n, m;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &pos[i]);
			}
			build(1, 1, N);
			ll res = 0;
			for9(i = 1; i <= N; i++)
			{
				dp[i] = query(1, 1, pos[i]);
				update(1, pos[i]);
			}
			ll sum = 0;
			for (i = 1; i <= N; i++)
			{
				ll t = N - pos[i] - (i - dp[i] - 1);
				res = (res - dp[i] * t);
				if (t >= 2)
				{
					res = (res + t*(t - 1) / 2 );
				}
				
			}
			printf("Case #%d: %lld\n", m, res%MOD);
		}
	}
	retunr 0;
}