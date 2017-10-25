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
const int maxn = 80000 + 100;
char A[maxn], B[maxn];
int main()
{
	int i, j, k, u, n, m, N, X, Y;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d", &N, &X, &Y);
			scanf("%s", A);
			scanf("%s", B);
			int cnt = 0;
			for (i = 0; i < N; i++)
			{
				if (A[i] != B[i])
				{
					cnt++;
				}
			}
			if (abs(X - Y) <= cnt && X + Y <= 2 * N - cnt)
				printf("Not lying\n");
			else
				printf("Lying\n");
		}
	}
	return 0;
}