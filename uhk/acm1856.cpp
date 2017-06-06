#include <cstdio>
#include <cstring>
using namespace std;
int set[10000002], s[10000002];
int main()
{
	int i, j, k, n, m, N, M, a, b, sum, max;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			printf("1\n");
			continue;
		}
		for (i = 0; i < 10000000; i++)
		{
			set[i] = i;
			s[i] = 1;
		}
		max = 0;
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			if (max < a)
				max = a;
			if (max < b)
				max = b;
			while (a != set[a])
				a = set[a];
			while (b != set[b])
				b = set[b];
			if (a != b)
			{
				if (s[a] > s[b])
				{
					set[b] = a;
					s[a] += s[b];
				}
				else
				{
					set[a] = b;
					s[b] += s[a];
				}
			}
		}
		sum = 0;
		for (i = 1; i <= max; i++)
		{
			if (sum < s[i])
				sum = s[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
