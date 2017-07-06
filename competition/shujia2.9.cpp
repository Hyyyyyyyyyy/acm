#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
const int maxn = 1000 + 100;
const int INF = 1000000000;
char ar[maxn];
char sa[maxn];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%s", ar);
			scanf("%s", sa);
			int L1 = strlen(ar);
			int L2 = strlen(sa);
			int res = 0;
			for (i = 0; i <= L1; i++)
			{
				if (ar[i] != sa[i])
				{
					res++;
				}
			}
			int doudou = 0;
			for (i = 0; i < L1; i++)
			{
				for (j = i + 1; j < L1; j++)
				{
					if (ar[i] == ar[j])
					{
						doudou = 1;
						break;
					}
				}
				if (doudou)
					break;
			}
			sort(ar, ar + L1);
			sort(sa, sa + L2);
			if (strcmp(ar, sa) != 0)
			{
				printf("NO\n");
			}
			else
			{
				if (res == 2 && doudou == 0)
				{
					printf("YES\n");
				}
				else if (res == 0 && doudou)
				{
					printf("YES\n");
				}
				else if (res == 2 && doudou)
				{
					printf("YES\n");
				}
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}