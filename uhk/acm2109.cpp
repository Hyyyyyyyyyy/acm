#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
	int i, j, k, n, m, ar[110000], sa[110000], china, jap;
	while (scanf("%d", &n) != EOF && n)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &ar[m]);
		}
		sort(ar + 1, ar + 1 + n);
		for (i = 1; i <= n; i++)
			scanf("%d", &sa[i]);
		sort(sa + 1, sa + 1 + n);
		china = 0;
		jap = 0;
		for (i = 1; i <= n; i++)
		{
			if (ar[i] > sa[i])
			{
				china += 2;
			}
			else if (ar[i] < sa[i])
			{
				jap+= 2;
			}
			else
			{
				china++;
				jap++;
			}
		}
		printf("%d vs %d\n", china, jap);
	}
	return 0;
}

