#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <cctype>
using namespace std;
const int maxn = 10000;
int N, M, K;
struct Node
{
	char name[50];
	int id;
	int num;
	int visit[20];
	int time[20];
	int sum;
};
Node ar[maxn];
bool comp(Node& a, Node& b)
{
	if (a.num != b.num)
	{
		return a.num > b.num;
	}
	else if (a.sum != b.sum)
	{
		return a.sum < b.sum;
	}
	else
		return a.id < b.id;
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	char s[10];
	while (scanf("%d %d %d", &N, &M, &K) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%s", ar[i].name);
			ar[i].id = i;
			memset(ar[i].visit, 0, sizeof(ar[i].visit));
			memset(ar[i].time, 0, sizeof(ar[i].time));
			ar[i].num = 0;
			ar[i].sum = 0;
		}
		for (i = 1; i <= M; i++)
		{
			scanf("%d %d %d %s", &a, &b, &c, s);
			if (strcmp(s, "AC") == 0)
			{
				if (!ar[b].visit[c])
				{
					ar[b].time[c] += a;
					ar[b].visit[c] = 1;
					ar[b].num++;
				}
			}
			else
			{
				if (!ar[b].visit[c])
				{
					ar[b].time[c] += 20;
				}
			}
		}
		for (u = 1; u <= N; u++)
		{
			for (j = 1; j <= K; j++)
			{
				if (ar[u].visit[j])
				{
					ar[u].sum += ar[u].time[j];
				}
			}
			//printf("%s %d %d\n", ar[i].name, ar[i].num, ar[i].sum);
		}
		sort(ar + 1, ar + 1 + N, comp);
		for(i = 1; i <= N; i++)
			printf("%s %d %d\n", ar[i].name, ar[i].num, ar[i].sum);
	}
	return 0;
}