#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
const int MAX = 100000000;
const int MIN = -10000000;
using namespace std;

int ar[110][110], n, d;
int dir[8][2] = { -1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1 };
int main()
{
	int i, j, k, u, max, temp;
	while (scanf("%d %d", &n, &d) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				scanf("%d", &ar[i][j]);
			}
		}
		max = MIN;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				for (u = 0; u < 8; u++)
				{
					temp = ar[i][j];
					for (k = 1; k < d; k++)
					{
						temp += ar[i + dir[u][0] * k][j + dir[u][1] * k];
						if (i + dir[u][0] * k < 1 || i + dir[u][0] * k > n || j + dir[u][1] * k < 1 || j + dir[u][1] * k > n)
						{
							temp = MIN;
							break;
						}
					}
					if (max < temp)
						max = temp;
				}
			}
		}
		printf("%d\n", max);
	}
	return 0;
}