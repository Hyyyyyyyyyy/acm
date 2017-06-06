#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int i, j, k, u, n, m, a, b, c, d, e, f;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if (b > d)
			{
				swap(b, d);
				swap(a, c);
			}
			if (a >= c)
			{
				printf("%d\n", b);
				continue;
			}
			int res = 0;
			for (i = 1; i <= b; i = j + 1)
			{
				j = min(b / (b / i), d / (d / i));
				if (i < a)
					j = min((a - 1) / ((a - 1) / i), j);
				if (i < c)
					j = min((c - 1) / ((c - 1) / i), j);
				if (b / i >(a - 1) / i && d / i >(c - 1) / i)
					res = j;
			}
			printf("%d\n", res);
		}
	}
	return 0;
}