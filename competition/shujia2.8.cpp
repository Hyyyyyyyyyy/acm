#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
const int maxn = 100;
int V, E, A, B;
int ar[maxn][maxn];
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			memset(ar, 0, sizeof(ar));
			scanf("%d %d %d %d", &V, &E, &A, &B);
			for (i = 1; i <= E; i++)
			{
				scanf("%d %d", &a, &b);
				ar[a][b] = ar[b][a] = 1;
			}
			if (!ar[A][B])
				printf("chsad\n");
			else
				printf("chhappy\n");
		}
	}
	return 0;
}