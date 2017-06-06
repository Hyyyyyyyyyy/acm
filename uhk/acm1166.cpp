#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int main()
{
	int i, n, m, j, k, u, p, q, a, b, ar[50010], sum, cas, doudou, temp;
	string s;
	while (scanf("%d", &n) != EOF)
	{
		cas = 1;
		for (m = 1; m <= n; m++)
		{
			doudou = 0;
			memset(ar, 0, sizeof(ar));
			scanf("%d", &p);
			for (i = 1; i <= p; i++)
			{
				scanf("%d", &temp);
				k = i;
				while (k <= p)
				{
					ar[k] += temp;
					k += k & -k;
				}
			}
			ar[0] = 0;
			while (cin >> s && s != "End")
			{
				scanf("%d %d", &a, &b);
				if (s == "Query")
				{
					k = b;
					sum = 0;
					while (k > 0)
					{
						sum += ar[k];
						k -= k & -k;
					}
					k = a - 1;
					while (k > 0)
					{
						sum -= ar[k];
						k -= k & -k;
					}
					if (!doudou)
					{
						printf("Case %d:\n", cas++);
					}
					doudou = 1;
					printf("%d\n", sum);
				}
				else if (s == "Add")
				{
					k = a;
					while (k <= p)
					{
						ar[k] += b;
						k += k & (-k);
					}
				}
				else if (s == "Sub")
				{
					k = a;
					while (k <= p)
					{
						ar[k] -= b;
						k += k & (-k);
					}
				}
			}
		}
	}
	return 0;
}