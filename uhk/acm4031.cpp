#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 20000 + 10;
int c1[maxn], c2[maxn], pro[maxn], cur[maxn], lt[maxn], rt[maxn];
int N, M, T;
char s[10];
void update(int x, int val)
{
	int t = x;
	while (t <= N)
	{
		c1[t] += val;
		t += t & -t;
	}
}
int sum(int x)
{
	int res = 0;
	int t = x;
	while (t >= 1)
	{
		res += c1[t];
		t -= t & -t;
	}
	return res;
}
int main()
{
	int i, j, k, u, n, m, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			int doudou = 0;
			scanf("%d %d %d", &N, &M, &T);
			memset(c1, 0, sizeof(c1));
			memset(c2, 0, sizeof(c2));
			memset(pro, 0, sizeof(pro));
			memset(cur, 0, sizeof(cur));
			memset(lt, 0, sizeof(lt));
			memset(rt, 0, sizeof(rt));
			int Time = 0;
			for (i = 1; i <= M; i++)
			{
				scanf("%s", s);
				if (s[0] == 'A')
				{
					scanf("%d %d", &a, &b);
					update(a, 1);
					update(b + 1, -1);
					lt[Time] = a;
					rt[Time++] = b;
				}
				else
				{
					if (!doudou)
						printf("Case %d:\n", m);
					doudou = 1;
					scanf("%d", &a);
					for (j = cur[a]; j < Time;)
					{
						if (lt[j] <= a && a <= rt[j])
						{
							pro[a]++;
							cur[a] = j + T;
							j += T;
						}
						else
						{
							j++;
						}
					}
					printf("%d\n", sum(a) - pro[a]);
				}
			}
		}
	}
	return 0;
}