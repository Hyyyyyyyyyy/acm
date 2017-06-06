#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
int main()
{
	int i, j, k, u, n, m, set[300], a, b, temp, max;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &k);
			memset(set, 0, sizeof(set));
			max = 0;
			for (i = 1; i <= k; i++)
			{
				scanf("%d %d", &a, &b);
				if (a % 2 == 0)
					a /= 2;
				else
					a = (a + 1) / 2;
				if (b % 2 == 0)
					b /= 2;
				else
					b = (b + 1) / 2;
				if (a > b)
				{
					temp = a;
					a = b;
					b = temp;
				}
				for (j = a; j <= b; j++)
					set[j]++;
			}
			for (i = 1; i <= 200; i++)
				max = (max < set[i]) ? set[i] : max;
			printf("%d\n", max*10);
		}
	}
	return 0;
}