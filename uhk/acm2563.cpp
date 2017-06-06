#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 100000000;

int main()
{
	int i, j, k, n, m, t;
	int ar[50];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &t);
			ar[1] = 1;
			ar[2] = 3;
			if (t == 1)
			{
				printf("1\n");
				continue;
			}
			else if (t == 2)
			{
				printf("3\n");
				continue;
			}
			else
			{
				for (i = 3; i <= t; i++)
				{
					ar[i] = ar[i - 1] + 2 * ar[i - 2];
				}
				printf("%d\n", ar[t]);
			}
		}
	}
	return 0;
}