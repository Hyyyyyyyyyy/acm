#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 2000 + 100;
const double eps = 1e-9;
int N, M, K;
double p1, p2, p3, p4;
double dp[maxn][maxn], c[maxn], e[maxn];
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d %d %lf %lf %lf %lf", &N, &M, &K, &p1, &p2, &p3, &p4) != EOF)
	{
		if (p4 < eps)
		{
			printf("0.00000\n");
			continue;
		}
		p2 = p2 / (1.0 - p1);
		p3 = p3 / (1.0 - p1);
		p4 = p4 / (1.0 - p1);
		e[0] = 1.0;
		for (i = 1; i <= N; i++)
			e[i] = e[i - 1] * p2;
		c[1] = p4;
		dp[1][1] = p4 / (1.0 - p2);
		for (i = 2; i <= N; i++)
		{
			for (j = 2; j <= K && j <= i; j++)
			{
				c[j] = p3*dp[i - 1][j - 1] + p4;
			}
			for (j = K + 1; j <= i; j++)
			{
				c[j] = p3*dp[i - 1][j - 1];
			}
			double t = 0.0;
			for (j = 1; j <= i; j++)
				t += e[i - j] * c[j];
			dp[i][i] = t / (1.0 - e[i]);
			dp[i][1] = p2*dp[i][i] + c[1];
			for (j = 2; j < i; j++)
			{
				dp[i][j] = p2*dp[i][j - 1] + c[j];
			}
		}
		printf("%.5f\n", dp[N][M]);
	}
	return 0;
}