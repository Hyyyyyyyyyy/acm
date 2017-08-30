#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100010;
char ar[maxn];
char former[maxn], latter[maxn];
int Next[maxn];
void GETnext(int n)      //有优化
{
	int i, j, k;
	int L = strlen(former);
	Next[0] = -1;
	i = 0;
	j = -1;
	while (i < L && j < L)
	{
		if (j == -1 || former[i] == former[j])
		{
			i++;
			j++;
			//优化
			if (former[i] == former[j])
				Next[i] = Next[j];
			else
				Next[i] = j;
			//如果不要优化，这样：
			//Next[i] = j;
		}
		else
			j = Next[j];
	}
}
int KMP(int n)       //返回目标串在主串中出现的次数
{
	int i, j;
	GETnext(n);
	int L1 = strlen(former);
	int L2 = strlen(latter);
	i = 0;
	j = 0;
	int res = 0;
	while (i < L2)
	{
		if (j == -1 || latter[i] == former[j])
		{
			if (j == L1 - 1)
			{
				return true;
			}
			i++;
			j++;
		}
		else
			j = Next[j];
	}
	return false;
}
int N;
int Maxi;
int Max;
int pos[maxn], Len[maxn];
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%d", &N);
			Max = 0;
			int B = 0;
			for (i = 1; i <= N; i++)
			{
				scanf("%s", &ar[B]);
				int L = strlen(&ar[B]);
				pos[i] = B;
				Len[i] = L;
				if (Max < L)
				{
					Max = L;
					Maxi = i;
				}
				B += L;
			}
			memcpy(latter, ar + pos[Maxi], Len[Maxi]);
			latter[Len[Maxi]] = '\0';
			bool doudou = true;
			for (i = 1; i <= N; i++)
			{
				if (i == Maxi)
					continue;
				memcpy(former, ar + pos[i], Len[i]);
				former[Len[i]] = '\0';
				if (!KMP(i))
				{
					doudou = false;
					break;
				}
			}
			if (doudou)
			{
				for (i = 0; i < Len[Maxi]; i++)
					printf("%c", ar[i + pos[Maxi]]);
				putchar('\n');
			}
			else
			{
				printf("No\n");
			}
		}
	}
	return 0;
}
