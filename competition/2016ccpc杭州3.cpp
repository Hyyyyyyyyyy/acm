#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int inf = 2147483647;
const ll INF = 9223372036854775807;
const double eps = 1e-8;
const int maxn = 100000 + 100;
ll ar[maxn];
ll sa[maxn];
ll T[maxn];
int main()
{
	ll i, j, n, m, N;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &N);
			ll cnt = 0ll;
			ar[0] = 0ll;
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
				sa[++cnt] = ar[i] - ar[i - 1];
			}
			ll res = 0ll;
			T[cnt] = 1ll;
			for (i = cnt - 1; i >= 1; i--)
			{
				ll t = sa[i] * T[i+1];
				if (t % sa[i + 1])
					T[i] = t / sa[i + 1] + 1;
				else
					T[i] = t / sa[i + 1];
			}
			for (i = 1; i <= cnt; i++)
			{
				res += T[i];
			}
			printf("Case #%lld: %lld\n", m, res);
		}
	}
	return 0;
}