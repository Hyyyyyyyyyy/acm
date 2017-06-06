#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	long long int i, j, k, u, n, m, a, b, c, t, sum, max, cost, ar[50100], sa[50100], hap, M, doudou;
	long long int *p, *q;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld %lld", &c, &cost);
			for (i = 1; i <= c; i++)
			{
				scanf("%lld", &ar[i]);
			}
			for (i = 1; i <= c; i++)
			{
				scanf("%lld", &sa[i]);
			}
			sum = 0;
			max = 0;
			hap = 0;
			M = 0;
			for (p = ar+1, q = ar, i = 0, j = 1; i <= c;)
			{
				if (sum - max <= cost)
				{
					if (M < hap)
						M = hap;
					q++;
					i++;
					if (i > c)
						break;
					sum += *q;
					hap += sa[i];
					max = (max > *q) ? max : *q;
				}
				else
				{
					sum -= *p;
					hap -= sa[j];
					p++;
					j++;
					max = 0;
					for (k = j; k <= i; k++)
					{
						if (max < ar[k])
							max = ar[k];
					}
				}
			}
			printf("%lld\n", M);
		}
	}
	return 0;
}









