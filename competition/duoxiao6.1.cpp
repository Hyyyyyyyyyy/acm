#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <vector>
#include <cctype>
#include <set>
using namespace std;
const int INF = 2147483640;
const double eps = 1e-7;
typedef long long ll;
const int maxn = 50000 + 100;
int A, B, C, D, E, F, G, N;
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			int Max = 0;
			for (i = 1; i <= N; i++)
			{
				scanf("%d %d %d %d %d %d %d", &A, &B, &C, &D, &E, &F, &G);
				int x = A - D - F + G;
				int y = B - D - E + G;
				int z = C - E - F + G;
				int w = D - G;
				int h = E - G;
				int k = F - G;
				int n = G;
				int res;
				if (x < 0 || y < 0 || z < 0 || w < 0 || h < 0 || k < 0 || n < 0)
					res = 0;
				else
					res = x + y + z + w + h + k + n;
				Max = max(res, Max);
			}
			printf("%d\n", Max);
		}

	}
	return 0;
}