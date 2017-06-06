#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int main()
{
	int i, n, m, j, k, u, p, q, a, b, ar[100010], sum, cas, doudou;
	while (scanf("%d", &n) != EOF && n)
	{
		memset(ar, 0, sizeof(ar));
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			k = a;
			while (k <= n)
			{
				ar[k]++;
				k += k & -k;
			}
			k = b+1;
			while (k <= n)
			{
				ar[k]--;
				k += k & -k;
			}
		}
		for (i = 1; i <= n; i++)
		{
			k = i;
			sum = 0;
			while (k)
			{
				sum += ar[k];
				k -= k & -k;
			}
			printf("%s%d", (i == 1) ? "\0":" ", (i == 1) ? ar[i]:sum );
		}
		putchar('\n');
	}
	return 0;
}