#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	long long i, j, k, u, n, m, ar[100010], sum, doudou;
	while (scanf("%lld", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%lld", &k);
			sum = 0;
			for (u = 1; u <= k; u++)
			{
				scanf("%lld", &ar[u]);
			}
			sort(ar+1, ar+1+k);
			for(i = 1; i <= k; i++)
			{
				if(ar[i] > sum + 1)
				{
					doudou = 1;
					break;
				}
				sum += ar[i];
			}
			printf("%lld\n", sum);
		}
	}
	return 0;
}
