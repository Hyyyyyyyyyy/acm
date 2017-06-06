#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
char ar[110][110], a[110], b[110];
int main()
{
	int i, j, k, n, m, u, min, Len, count, index, p, q, max, doudou;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			min = MAX;
			for (u = 1; u <= k; u++)
			{
				scanf("%s", ar[u] + 1);
				Len = strlen(ar[u] + 1);
				if (min > Len)
				{
					min = Len;
					index = u;
				}
			}
			max = 0;
			for (i = 1; i <= min; i++)
			{
				for (j = min; j >= i; j--)
				{
					for (u = i; u <= j; u++)
					{
						a[u - i + 1] = ar[index][u];
						b[j - u + 1] = ar[index][u];
					}
					a[j - i + 2] = '\0';
					b[j - i + 2] = '\0';
					//puts(a+1);
					//puts(b+1);
					count = 0;
					for (u = 1; u <= k; u++)
					{
						if (strstr(ar[u]+1, a+1) || strstr(ar[u]+1, b+1))
							count++;
					}
					//printf("%d\n\n", count);
					if (count == k && max < j-i+1)
						max = j-i+1;
				}
			}
			printf("%d\n", max);
		}
	}
	return 0;
}
