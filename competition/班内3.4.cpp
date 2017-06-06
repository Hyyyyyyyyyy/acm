#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
ll ar[maxn];
ll sa[maxn];
ll t;
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d %d %d", &n, &m, &c) != EOF)
	{
		sa[0] = 0;
		for (i = 1; i <= n; i++)
		{
			scanf("%lld", &ar[i]);
			sa[i] = sa[i - 1] + ar[i];
		}
		sort(sa, sa + n+1);
		ll res = 0;
		for (i = 1; i <= m; i++)
		{
			ll temp = sa[n-i+1] - sa[i-1];
			if (temp < 0)
				temp = -temp;
			if(temp-c>0)
				res += temp - c;
		}
		printf("%lld\n", res);
	}
	return 0;
}
