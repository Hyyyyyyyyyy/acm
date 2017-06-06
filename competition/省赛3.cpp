#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
map<char*, int>ar;
int sa[300][50];
int bb[300][50];
int main()
{
	int i, j, k, u, n, m, a, b, c, x, y,q, max, min, flag, res, h, l, doudou;
	char s[300][50];
	char ss[50];
	char *p;
	while (scanf("%d", &x) != EOF)
	{
		for (y = 1; y <= x; y++)
		{
			ar.clear();
			memset(sa, 0, sizeof(sa));
			memset(bb, 0, sizeof(bb));
			scanf("%d %d", &n, &q);
			scanf("%d", &c);
			for (i = 1; i <= c; i++)
			{
				scanf("%s", ss);
				strcpy(s[i], ss);
			}
			for (i = 1; i <= q; i++)
			{
				scanf("%d", &a);
				for (j = 1; j <= a; j++)
				{
					scanf("%s", ss);
					for (h = 1; h <= c; h++)
					{
						if (strcmp(s[h], ss) == 0)
							break;
					}
					sa[h][i] = 1;
				}
			}
			for (i = 1; i <= n; i++)
			{
				for (j = 1; j <= q; j++)
				{
					cin >> bb[i][j];
				}
			}
			for (i = 1; i <= n; i++)
			{
				doudou = 0;
				for (j = 1; j <= c; j++)
				{
					flag = 1;
					for (h = 1; h <= q; h++)
					{
						if (sa[j][h] != bb[i][h])
						{
							flag = 0;
							break;
						}
					}
					if (flag)
					{
						doudou++;
						res = j;
					}
				}
				if (doudou != 1)
				{
					printf("Let's go to the library!!\n");
				}
				else
					printf("%s\n", s[res]);
			}
		}
	}
	return 0;
}