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
ll stack[maxn];
int main()
{
	ll i, n, m;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &N, &M);         //N为所给的数的个数， M为所要覆盖的区间最大值
			for (i = 1; i <= N; i++)
			{
				scanf("%lld", &ar[i]);
			}
			sort(ar + 1, ar + 1 + N);
			ll cur = 0;
			ll cnt = 0;
			for (i = 1; i <= N; i++)
			{
				while (cur < ar[i] - 1)
				{
					stack[++cnt] = cur + 1;
					cur += cur + 1;
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
			printf("%lld\n", cnt);      //cnt为覆盖区间需要的最小数字个数，stack数组存的是需要的数字
			for(i = 1; i <= cnt; i++)
				printf("%d ", stack[i]);
			putchar('\n');
		}
	}
	return 0;
}
