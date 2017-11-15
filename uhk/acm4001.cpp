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
template<class T>
T min(T& a, T& b) { return (a < b ? a : b); }
template<class T>
T max(T& A, T& B) { return (A > B ? A : B); }
const int maxn = 1000 + 100;
const int maxm = 1000000 + 100;
int N;
ll dp[maxn];
struct Node
{
	ll a;
	ll b;
	ll c;
	ll d;
	Node() {}
	Node(ll x, ll y, ll z, ll w) : a(x), b(y), c(z), d(w) {}
	Node(const Node& p)
	{
		a = p.a;
		b = p.b;
		c = p.c;
		d = p.d;
	}
};
Node node[maxn];
bool comp(const Node& a, const Node& b)
{
	if (a.a != b.a)
		return a.a < b.a;
	else if (a.b != b.b)
		return a.b < b.b;
	return a.d > b.d;
}
bool check(int n, int m)
{
	if (node[n].d == 0 && node[n].a >= node[m].a && node[n].b >= node[m].b)
		return true;
	if (node[n].d == 1 && (node[n].a >= node[m].a && node[n].b >= node[m].b) && node[n].a*node[n].b > node[m].a*node[m].b)
		return true;
	if (node[n].d == 2 && node[n].a > node[m].a && node[n].b > node[m].b)
		return true;
	return false;
}
int main()
{
	int i, j, k, n, m;
	ll a, b, c, d;
	while (scanf("%d", &N) != EOF && N)
	{
		for9(i = 1; i <= N; i++)
		{
			scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
			if (a < b)
				swap(a, b);
			node[i] = Node(a, b, c, d);
		}
		sort(node + 1, node + 1 + N, comp);
		node[0] = Node(0, 0, 0, 0);
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= N; i++)
		{
			for (j = i - 1; j >= 0; j--)
			{
				if (check(i, j))
					dp[i] = max(dp[i], dp[j] + node[i].c);
			}
		}
		ll Max = 0;
		for (i = 1; i <= N; i++)
		{
			Max = max(Max, dp[i]);
		}
		printf("%lld\n", Max);
	}
	return 0;
}