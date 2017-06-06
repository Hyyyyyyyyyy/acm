#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
	int i, j, k, u, n, m, a, b, x, y, z, h, count;
	char s[5];
	int set[20], ti, time[20];
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			memset(set, 0, sizeof(set));
			memset(time, 0, sizeof(time));
			scanf("%d %d", &a, &b);
			count = 0;
			ti = 0;
			for (u = 1; u <= b; u++)
			{
				scanf("%d%d:%d%s", &x, &y, &z, s);
				x %= 100;
				if (s[0] == 'A' && !set[x])
				{
					set[x] = 1;
					time[x] += y * 60 + z;
					ti += time[x];
					count++;
				}
				else
				{
					if (!set[x])
					{
						time[x] += 20;
					}
				}
			}
			printf("%d %d\n", count, ti);
		}
	}
	return 0;
}
