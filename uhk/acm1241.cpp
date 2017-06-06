#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAX = 10000000;
int visit[110][110];
char ar[110][110];
int cnt, a, b, N;
int dir[8][2] = { -1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1 };
bool dfs(int x, int y);
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d %d", &a, &b) != EOF && (a || b))
	{
		for (i = 1; i <= a; i++)
		{
			scanf("%s", ar[i] + 1);
		}
		memset(visit, 0, sizeof(visit));
		cnt = 0;
		N = 1;
		for (i = 1; i <= a; i++)
		{
			for (j = 1; j <= b; j++)
			{
				if (ar[i][j] == '@' && !visit[i][j])
				{
					dfs(i, j);
					cnt++;
				}
				N++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
bool dfs(int x, int y)
{
	int i, j, k, u, doudou = 0;
	int nowx, nowy;
	for (i = 0; i < 8; i++)
	{
		nowx = x + dir[i][0];
		nowy = y + dir[i][1];
		if (nowx > a || nowy > b || nowx < 1 || nowy < 1 || ar[nowx][nowy] == '*')
			continue;
		if (visit[nowx][nowy])
			continue;
		visit[nowx][nowy] = N;
		doudou = 1;
		dfs(nowx, nowy);
	}
	if (doudou)
		return true;
	else
		return false;
}