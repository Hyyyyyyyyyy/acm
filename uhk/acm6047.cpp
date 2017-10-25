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
const int INF = 1e9 + 1;
const int maxn = 1500000 + 100;
const ll MOD = 1e9 + 7;
int A[maxn], B[maxn];
int Max[maxn];
int main()
{
	int i, j, k, u, n, m, N, M;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &A[i]);
		}
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &B[i]);
		}
		memset(Max, 0, sizeof(Max));
		Max[N] = A[N] - N;
		for (i = N - 1; i >= 1; i--)
		{
			Max[i] = max(Max[i + 1], A[i] - i);
		}
		sort(B + 1, B + N + 1);
		ll res = 0;
		res = (res + Max[B[1]]) % MOD;
		M = Max[B[1]] - (N + 1);
		for (i = 2; i <= N; i++)
		{
			res = (res + max(Max[B[i]], M)) % MOD;
			M = max(M, max(Max[B[i]], M) - (N + i));
		}
		printf("%lld\n", res);
	}
	return 0;
}