#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
const int maxn = 100000 + 1000;
char former[maxn], latter[2*maxn];
int exnext[2*maxn], extend[2*maxn], Next[maxn];
void GETnext(int L)
{
	int i, j, k;
	Next[0] = -1;
	i = 0;
	j = -1;
	while (i < L && j < L)
	{
		if (j == -1 || former[i] == former[j])
		{
			i++;
			j++;
			if (former[i] == former[j])
				Next[i] = Next[j];
			else
				Next[i] = j;
		}
		else
			j = Next[j];
	}
}
void GETexnext(int L)
{
	int i, j, k;
	exnext[0] = L;
	i = 1;
	j = 0;
	while (former[i + j] == former[j] && i + j < L)
		j++;
	exnext[1] = j;
	k = 1;
	for (i = 2; i < L; i++)
	{
		int p = k + exnext[k] - 1;
		int l = exnext[i - k];
		if (i + l < p + 1)
		{
			exnext[i] = l;
		}
		else
		{
			j = max(0, p - i + 1);
			while (i + j < L && former[j] == former[i + j])
				j++;
			exnext[i] = j;
			k = i;
		}
	}
}
void GETextend(int L1, int L2)
{
	int i, j, k;
	GETexnext(L1);
	i = 0;
	j = 0;
	while (j < L1 && j < L2 && former[j] == latter[j])
		j++;
	extend[0] = j;
	k = 0;
	for (i = 1; i < L2; i++)
	{
		int p = extend[k] + k - 1;
		int l = exnext[i - k];
		if (i + l < p + 1)
		{
			extend[i] = l;
		}
		else
		{
			j = max(0, p - i + 1);
			while (j < L1 && i + j < L2 && former[j] == latter[i + j])
				j++;
			extend[i] = j;
			k = i;
		}
	}
}
int main()
{
	int i, j, k, u, n, m, cas;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%s", former);
			strcpy(latter, former);
			strcat(latter, former);
			int L1 = strlen(former);
			int L2 = strlen(latter);
			GETextend(L1, L2);
			int cnt1, cnt2, cnt3;
			cnt1 = cnt2 = cnt3 = 0;
			for (i = 0; i < L1; i++)
			{
				if (extend[i] >= L1)
				{
					cnt2++;
				}
				else
				{
					if (latter[i + extend[i]] > former[extend[i]])
					{
						cnt3++;
					}
					else
					{
						cnt1++;
					}
				}
			}
			GETnext(L1);
			int t = L1 - Next[L1];
			int tot = 1;
			if (L1 % t == 0)
			{
				tot = L1 / t;
			}
			printf("Case %d: %d %d %d\n", m, cnt1 / tot, cnt2 / tot, cnt3 / tot);
			//puts(former);
			//puts(latter);
			//for (i = 0; i < L2; i++)
			//	printf("%d ", extend[i]);
			//putchar('\n');
		}
	}
	return 0;
}
