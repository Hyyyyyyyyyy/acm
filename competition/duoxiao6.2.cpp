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
const int maxn = 20000 + 100;
int M;
char S[maxn];
int sum[maxn];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &M);
			scanf("%s", S);
			int L = strlen(S);
			int Max = 0;
			for (i = 0; i < L; i++)
			{
				int res = 0;
				int top = 1;
				for (j = 1; i + j < L && i - j >= 0; j++)
				{
					int t = S[i - j] - S[i + j];
					t = abs(t);
					res += t;
					while (res > M)
					{
						res -= abs(S[i - top] - S[i + top]);
						top++;
					}
					Max = max(j - top + 1, Max);
				}
			}
			for (i = 0; i < L; i++)
			{
				int res = 0;
				int top = 1;
				for (j = 1; i + j < L && i - j + 1 >= 0; j++)
				{
					int t = S[i - j + 1] - S[i + j];
					t = abs(t);
					res += t;
					while (res > M)
					{
						res -= abs(S[i - top + 1] - S[i + top]);
						top++;
					}
					Max = max(j - top + 1, Max);
				}
			}
			printf("%d\n", Max);
		}
	}
	return 0;
}