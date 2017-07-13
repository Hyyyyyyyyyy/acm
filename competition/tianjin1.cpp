#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e7 + 100;
const int INF = 1e9;
typedef long long ll;
int N;
int sa[maxn];
int MAX;
int dp;
int main()
{
	int i, j, n, m;
	int MAX = -INF;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			dp = INF;
			MAX = 0;
			for (i = 1; i <= N; i++)
			{
				scanf("%d", &sa[i]);
				MAX = max(MAX, sa[i] - dp);
				dp = min(sa[i], dp);
			}
			printf("%d\n", MAX);
		}
		return 0;
	}
}