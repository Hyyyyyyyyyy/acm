#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100000 + 100;
int ar[maxn];
int visit[maxn];
int main()
{
	int i, j, k, u, n, m, cnt = 0;
	memset(visit, 0, sizeof(visit));
	memset(ar, 0, sizeof(ar));
	for (i = 2; i*i <= maxn; i++)
	{
		if (visit[i])
			continue;
		for (j = i*i; j <= maxn; j += i)
		{
			visit[j] = 1;
		}
	}
	for (i = 4; i <= maxn; i++)
	{
		if (!visit[i] && !visit[i - 2])
		{
			cnt++;
		}
		ar[i] = cnt;
	}
	while (scanf("%d", &n) != EOF && n > 0)
	{
		printf("%d\n", ar[n]);
	}
	return 0;
}