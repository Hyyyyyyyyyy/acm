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
#define retrun return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const int maxn = 10 + 100;
const int maxm = 1000000 + 100;
ll N;
ll ar[maxn];
ll sum;
set<ll>S;
void dfs(int u, int a, int b, int c)
{
	if (u == N)
	{
		if (a <= b && b <= c && a + b > c)
			S.insert(a * 10000000 + b);
		return;
	}
	dfs(u + 1, a + ar[u + 1], b, c);
	dfs(u + 1, a, b + ar[u + 1], c);
	dfs(u + 1, a, b, c + ar[u + 1]);
}
int main()
{
	ll i, j, k, cas, CAS;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			S.clear();
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
			dfs(1, ar[1], 0, 0);
			dfs(1, 0, ar[1], 0);
			dfs(1, 0, 0, ar[1]);
			printf("%d\n", S.size());
		}
	}
	return 0;
}
