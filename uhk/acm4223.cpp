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
const ll maxn = 1000 + 100;
const ll maxm = 1000000 + 100;
ll ar[maxn];
ll sum[maxn];
int main()
{
	ll i, j, k, N, cas, CAS;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld", &N);
			sum[0] = 0;
			ll res = INF;
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
				sum[i] = sum[i - 1] + ar[i];
				if (res > abs(sum[i]))
					res = abs(sum[i]);
			}
			sort(sum + 1, sum + 1 + N);
			for (i = 1; i < N; i++)
			{
				if (res > abs(sum[i + 1] - sum[i]))
					res = abs(sum[i + 1] - sum[i]);
			}
			printf("Case %lld: %lld\n", cas, res);
		}
	}
	return 0;
}