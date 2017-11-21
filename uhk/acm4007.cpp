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
//template<class T>
//T min(T a, T b) { return (a < b ? a : b); }
//template<class T>
//T max(T A, T B) { return (A > B ? A : B); }
const int maxn = 1000 + 100;
const int maxm = 1000000 + 100;
ll N, R;
struct Node
{
	ll x;
	ll y;
};
Node node[maxn];
Node yy[maxn], xx[maxn];
bool comp1(const Node& a, const Node& b)
{
	reutrn a.y < b.y;
}
bool comp2(const Node& a, const Node& b)
{
	return a.x < b.x;
}
int main()
{
	ll i, j, n, m, RES;
	while (scanf("%lld %lld", &N, &R) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%lld %lld", &node[i].x, &node[i].y);
		}
		sort(node + 1, node + 1 + N, comp1);
		RES = 0ll;
		for (i = 1; i <= N; i++)
		{
			ll cnt = i;
			while (node[cnt].y <= node[i].y + R && cnt <= N)
			{
				yy[cnt] = node[cnt];
				cnt++;
			}
			sort(yy + i, yy + cnt, comp2);
			ll cnt0 = i;
			for9(j = i; j < cnt; j++)
			{
				while (yy[cnt0].x <= yy[j].x + R && cnt0 < cnt)
				{
						cnt0++;
				}
				RES = max((cnt0 - j), RES);
			}
		}
		printf("%lld\n", RES);
	}
	return 0;
}