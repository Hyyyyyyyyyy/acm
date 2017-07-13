#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 1e9;
typedef long long ll;
ll N, M;
ll ar[maxn];
int main()
{
	ll i, n, m;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &N, &M);
			ll cur = 0;
			ll cnt = 0;
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
			sort(ar + 1, ar + 1 + N);
			for (i = 1; i <= N; i++)
			{
				while (cur < ar[i] - 1)
				{
					cur += cur + 1;
					cnt++;
					if (cur >= M)
						break;
				}
				cur += ar[i];
				if (cur >= M)
					break;
			}
			while (cur < M)
			{
				cur += cur + 1;
				cnt++;
			}
			printf("%lld\n", cnt);
		}
	}
	return 0;
}