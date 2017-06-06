#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
const int MAX = 100000000;
using namespace std;
int visit[110];
int ar[110][110];
int link[110];
int leftN, rightN, res;
bool dfs(int f);

int main()
{
	int i, j, k, u, n, m, num;
	while (scanf("%d", &leftN) != EOF && leftN)
	{
		scanf("%d %d", &rightN, &num);
		memset(ar, 0, sizeof(ar));
		memset(link, -1, sizeof(link));
		res = 0;
		for (i = 0; i < num; i++)
		{
			scanf("%d %d %d", &k, &n, &m);
			ar[n][m] = 1;
		}
		for (i = 1; i < leftN; i++)
		{
			memset(visit, false, sizeof(visit));
			if (dfs(i))
				res++;
		}
		printf("%d\n", res);
	}
	return 0;
}
bool dfs(int f)
{
	int i, j, k, u;
	for (i = 1; i <= rightN; i++)
	{
		if (!visit[i] && ar[f][i])
		{
			visit[i] = true;
			if (link[i] == -1 || dfs(link[i]))
			{
				link[i] = f;
				return true;
			}
		}
	}
	return false;
}
