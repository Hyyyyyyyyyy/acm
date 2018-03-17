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
const ll inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const ll maxn = 100000 + 100;
const ll maxm = 1000000 + 100;
struct Node
{
	ll c;
	ll d;
};
Node node[maxn];
bool comp(Node &a, Node& b)
{
	return a.d < b.d;
}
int main()
{
	ll i, j, k, cas, CAS, N, a, b;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld %lld", &node[i].c, &node[i].d);
			}
			sort(node + 1, node + 1 + N, comp);
			ll now = 0;
			ll res = 0;
			for (i = 1; i <= N; i++)
			{
				now = now + node[i].c;
				if (now - node[i].d > 0)
					res = max(res, now - node[i].d);
			}
			printf("Case %lld: %lld\n", cas, res);
		}
	}
	return 0;
}