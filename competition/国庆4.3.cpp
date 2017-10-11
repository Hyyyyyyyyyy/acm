#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 1200000 + 100;
char s[maxn];
int Next[maxn];
int visit[maxn];
int res[maxn];
int main()
{
	int i, j, k, n, m, a, b, N, Q;
	char ch[5];
	while (scanf("%d %d", &N, &Q) != EOF)
	{
		scanf("%s", s);
		memset(visit, 0, sizeof(visit));
		memset(res, 0, sizeof(res));
		Next[0] = -1;
		j = -1;
		i = 0;
		while (i < N && j < N)
		{
			if (j == -1 || s[i] == s[j])
			{
				i++;
				j++;
				Next[i] = j;
			}
			else
				j = Next[j];
		}
		int cnt = N;
		for (i = 1; i <= Q; i++)
		{
			scanf("%d", &a);
			if (a == 1)
			{
				scanf("%s", ch);
				s[cnt++] = ch[0];
				while (j != -1 && s[cnt - 1] != s[j])
					j = Next[j];
				j++;
				Next[cnt] = j;
				res[cnt] += res[j];
			}
			else if (a == 2)
			{
				if (visit[cnt] == 0)
					res[cnt]++;
				visit[cnt] = 1;
			}
			else
			{
				printf("%d\n", res[cnt]);
			}
		}
	}
	return 0;
}