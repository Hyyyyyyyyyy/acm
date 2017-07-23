#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int maxn = 100000 + 100;
char latter[maxn], former[maxn];
int Next[maxn];
void GETnext()      //有优化
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
int KMP()       //返回目标串在主串中出现的次数
{
	int i, j;
	GETnext();
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
				return 1;
			}
			i++;
			j++;
		}
		else
			j = Next[j];
	}
	return 0;
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			scanf("%s %s", latter, former);
			int L1 = strlen(latter);
			int L2 = strlen(former);
			if (L2 == 1 && former[0] == '0')
			{
				printf("Alice\n");
				continue;
			}
			if (L1 < L2)
			{
				printf("Bob\n");
			}
			else
			{
				if (KMP())
				{
					printf("Alice\n");
				}
				else
				{
					reverse(latter, latter+L1);
					if (KMP())
					{
						printf("Alice\n");
					}
					else
					{
						printf("Bob\n");
					}
				}
			}
		}
	}
	return 0;
}