#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAN = 100000000;
int main()
{
	int i, j, k, n, m, u, a, b;
	int ar[32010], sa[32010], sum;
	while (scanf("%d", &n) != EOF)
	{
		memset(ar, 0, sizeof(ar));
		memset(sa, 0, sizeof(sa));
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			a++;
			k = a;
			sum = 0;
			while (k)
			{
				sum += ar[k];
				k -= k & -k;
			}
			sa[sum]++;
			k = a;
			while (k <= 32000)
			{
				ar[k] += 1;
				k += k & -k;
			}
		}
		for (i = 0; i < n; i++)
		{
			printf("%d\n", sa[i]);
		}
	}
	return 0;
}