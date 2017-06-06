#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 1000000 + 100;
int s[maxn], visit[maxn * 2];
char ar[maxn];
map<char, int>q;
int N, M;
int main()
{
	q['W'] = 1;
	q['T'] = 2;
	int i, j, k, u, n, m;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		scanf("%s", ar + 1);
		memset(visit, 0, sizeof(visit));
		s[0] = 0;
		for (i = 1; i <= N; i++)
		{
			s[i] = s[i - 1] + q[ar[i]];
			visit[s[i]] = i;
		}
		for (m = 1; m <= M; m++)
		{
			scanf("%d", &k);
			if (k > s[N])
			{
				printf("NIE\n");
				continue;
			}
			if (visit[k])
			{
				printf("TAK\n");
				continue;
			}
			if (visit[k + 1])
			{
				int doudou = 0;
				int l = 1;
				int r = visit[k + 1];
				while (r <= N)
				{
					if ((ar[l] == 'W' && ar[r] == 'T') || (ar[l] == 'T' && ar[r] == 'W') || (ar[l] == 'W' && ar[r] == 'W'))
					{
						doudou = 1;
						break;
					}
					l++;
					r++;
				}
				if (!doudou)
					printf("NIE\n");
				else
					printf("TAK\n");
			}
			else
			{
				printf("NIE\n");
			}
		}
	}
	return 0;
}