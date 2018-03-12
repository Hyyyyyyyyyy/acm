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
const int maxn = 100000 + 100;
const int maxm = 100000 + 100;
ll ar[maxn];
ll N, M;
int main()
{
	ll i, j, k, n, m, cas, CAS;
	while (scanf("%lld", &CAS) != EOF)
	{
		for (cas = 1; cas <= CAS; cas++)
		{
			scanf("%lld %lld", &N, &M);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
			sort(ar + 1, ar + 1 + N);
			ll res = 0;
			for (i = 1, j = 2 * M; i < j; i++, j--)
			{
				res += ar[i] * ar[j];
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}