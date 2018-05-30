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
const ll maxn = 2000 + 100;
const ll maxm = 1000000 + 100;
ll N, X, Y, Z;
ll RES;
void dfs(ll sum, ll n, ll t)
{
	if (t >= RES)
		return;
	ll cnt = (Z - sum) / n;
	if ((Z - sum) % n)
		cnt++;
	RES = min(RES, t + cnt);
	if (sum >= X)
	{
		dfs(sum - (sum / X)*X, n + (sum / X)*Y, t);
	}
	else
	{
		cnt = (X - sum) / n;
		if ((X - sum) % n)
			cnt++;
		dfs(sum + cnt * n, n, t + cnt);
	}
}
int main()
{
	ll i, j, k, CAS, cas;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld %lld %lld", &N, &X, &Y, &Z);
			RES = inf;
			dfs(0, N, 0);
			printf("%lld\n", RES);
		}
	}
	return 0;
}