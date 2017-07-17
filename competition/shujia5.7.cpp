#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 2147483640;
const int maxn = 100000 + 100;
ll ar[maxn], sa[maxn];
ll N, res;
int main()
{
	ll i, j, k, u, n, m;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &N);
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
			res = 0;
			for (i = 1; i <= N; i++)
			{
				sa[ar[i]] = i;
				res += (N - i + 1) * (i - 1);
			}
			for (i = 1; i < N; i++)
			{
				ll a = sa[i];
				ll b = sa[i + 1];
				if (a > b)
				{
					swap(a, b);
				}
				res -= (N - b + 1)*a;
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}