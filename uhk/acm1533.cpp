#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int ar[110][110];
char sa[110][110];
bool visitx[110], visity[110];
int lx[110], ly[110];
int link[110];
int N, M, Cntx, Cnty;
int KM();
bool dfs(int f);
int main()
{
	int i, j, k, u, n, m, a, b, c, res;
	while (scanf("%d %d", &N, &M) != EOF && (N || M))
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%s", sa[i] + 1);
		}
		memset(link, -1, sizeof(link));
		memset(ar, 0, sizeof(ar));
		Cntx = Cnty = 1;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				if (sa[i][j] == 'm')
				{
					for (a = 1; a <= N; a++)
					{
						for (b = 1; b <= M; b++)
						{
							if (sa[a][b] == 'H')
							{
								ar[Cntx][Cnty++] = (-1)*(abs(i - a) + abs(j - b));
							}
						}
					}
					Cntx++;
					Cnty = 1;
				}
			}
		}
		//for (i = 1; i < Cntx; i++)
		//{
		//	for (j = 1; j < Cntx; j++)
		//	{
		//		printf("%d ", ar[i][j]);
		//	}
		//	putchar('\n');
		//}
		Cntx -= 1;
		Cnty = Cntx;
		printf("%d\n", -KM());
	}
	return 0;
}
int KM()
{
	int i, j, k, u, n, m, temp, d, res;
	for (i = 1; i <= Cnty; i++)
		lx[i] = MIN;
	memset(ly, 0, sizeof(ly));
	for (i = 1; i <= Cntx; i++)
	{
		for (j = 1; j <= Cnty; j++)
		{
			lx[i] = (lx[i] < ar[i][j]) ? ar[i][j] : lx[i];
		}
	}
	for (i = 1; i <= Cntx; i++)
	{
		while (1)
		{
			memset(visitx, false, sizeof(visitx));
			memset(visity, false, sizeof(visity));
			temp = MAX;
			if (dfs(i))
				break;
			for (u = 1; u <= Cntx; u++)
			{
				if (visitx[u])
				{
					for (j = 1; j <= Cnty; j++)
					{
						if (!visity[j])
						{
							temp = (temp < lx[u] + ly[j] - ar[u][j]) ? temp : (lx[u] + ly[j] - ar[u][j]);
						}
					}
				}
			}
			for (k = 1; k <= Cntx; k++)
			{
				if (visitx[k])
					lx[k] -= temp;
				if (visity[k])
					ly[k] += temp;
			}
		}
	}
	//printf("%d %d\n", Cntx, Cnty);
	//for (i = 1; i <= Cntx; i++)
	//	printf("%d ", link[i]);
	//putchar('\n');
	res = 0;
	for (i = 1; i <= Cntx; i++)
		if (link[i] != -1)
			res += ar[link[i]][i];
	return res;
}
bool dfs(int f)
{
	int i, j, k, temp;
	visitx[f] = true;
	for (i = 1; i <= Cnty; i++)
	{
		if (!visity[i] && lx[f] + ly[i] == ar[f][i])
		{
			visity[i] = true;
			if (link[i] == -1 || dfs(link[i]))
			{
				link[i] = f;
				return true;
			}
		}
	}
	return false;
}
