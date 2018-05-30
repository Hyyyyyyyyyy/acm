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
const ll MOD = 1e7 + 7;
const ll maxn = 1000 + 100;
const ll maxm = 1000000 + 100;
struct Node
{
	char s[20];
	ll val;
};
Node node[maxn];
bool comp(Node& a, Node& b)
{
	if (a.val == b.val)
		if (strcmp(a.s, b.s) < 0)
			return 1;
		else
			return 0;
	return a.val > b.val;
}
int main()
{
	ll i, j, k, CAS, cas, N, M;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld", &N, &M);
			for (i = 1; i <= N; i++)
			{
				scanf("%s %lld", node[i].s, &node[i].val);
			}
			sort(node + 1, node + 1 + N, comp);
			ll res = 0;
			for (i = 1; i <= M; i++)
			{
				res += (M + 1 - i)*node[i].val;
			}
			printf("%lld", res);
			for (i = 1; i <= M; i++)
			{
				printf(" %s", node[i].s);
			}
			putchar('\n');
		}
	}
	return 0;
}