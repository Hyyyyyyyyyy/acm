#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 40005;
const int maxm = 4000005;
bool ar[1010][1010], sa[1010][1010];
int N, M, K, P;
char s1[20], s2[20];
int num[1010];
int main()
{
	int i, j, n, m, a, b, c;
	while (scanf("%d %d %d", &N, &M, &K) != EOF && N + M + K)
	{
		scanf("%d", &P);
		memset(ar, false, sizeof(ar));
		memset(sa, false, sizeof(sa));
		memset(num, 0, sizeof(num));
		for (i = 1; i <= P; i++)
		{
			scanf("%s %d %s %d", s1, &a, s2, &b);
			if (s1[0] == 'c' && s2[0] == 'p')
			{
				ar[a][b] = true;
			}
			if (s1[0] == 'p' && s2[0] == 's')
			{
				sa[a][b] = true;
				num[a]++;
			}
		}
		ll res = 0;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (ar[i][j])
				{
					res += K;
					res -= num[j];
				}
			}
		}
		for (i = 1; i <= M; i++)
		{
			for (j = 1; j <= K; j++)
			{
				if (sa[i][j])
				{
					res += N;
				}
			}
		}

		printf("%lld\n", (ll)N*(ll)M*(ll)K - res);
	}
	return 0;
}
