#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int MAX = 100000000;
int main()
{
	int i, j, k, n, m, a, b, c, p, q, ar[1010][1010], sa[1010][1010], cas, sum, doudou, x1, x2, y1, y2, temp;
	char s[5];
	while (scanf("%d", &n) != EOF)
	{
		cas = 1;
		for (m = 1; m <= n; m++)
		{
			doudou = 0;
			scanf("%d", &p);
			memset(ar, 0, sizeof(ar));
			memset(sa, 0, sizeof(sa));
			for (i = 1; i <= 1005; i++)
			{
				for (j = 1; j <= 1005; j++)
				{
					ar[i][j] = 1;
					for (a = i; a <= 1005; a += (a & (-a)))
					{
						for (b = j; b <= 1005; b += (b & (-b)))
						{
							sa[a][b] += 1;
						}
					}
				}
			}
			for (q = 1; q <= p; q++)
			{
				scanf("%s", s);
				if (!strcmp(s, "S"))
				{
					sum = 0;
					scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
					x1++;
					y1++;
					x2++;
					y2++;
					if (x1 > x2)
					{
						temp = x1;
						x1 = x2;
						x2 = temp;
					}
					if (y1 > y2)
					{
						temp = y1;
						y1 = y2;
						y2 = temp;
					}
					for (i = x2; i > 0; i -= (i & (-i)))
					{
						for (j = y2; j > 0; j -= (j & (-j)))
						{
							sum += sa[i][j];
						}
					}
					for (i = x1 - 1; i > 0; i -= (i & (-i)))
					{
						for (j = y2; j > 0; j -= (j & (-j)))
						{
							sum -= sa[i][j];
						}
					}
					for (i = x2; i > 0; i -= (i & (-i)))
					{
						for (j = y1 - 1; j > 0; j -= (j & (-j)))
						{
							sum -= sa[i][j];
						}
					}
					for (i = x1 - 1; i > 0; i -= (i & (-i)))
					{
						for (j = y1 - 1; j > 0; j -= (j & (-j)))
						{
							sum += sa[i][j];
						}
					}
					if (!doudou)
						printf("Case %d:\n", cas++);
					doudou = 1;
					printf("%d\n", sum);
				}
				else if (!strcmp(s, "A"))
				{
					scanf("%d %d %d", &x1, &y1, &c);
					x1++;
					y1++;
					for (i = x1; i <= 1005; i += (i & (-i)))
					{
						for (j = y1; j <= 1005; j += (j & (-j)))
						{
							sa[i][j] += c;
						}
					}
					ar[x1][y1] += c;
				}
				else if (!strcmp(s, "D"))
				{
					scanf("%d %d %d", &x1, &y1, &c);
					x1++;
					y1++;
					if (c >= ar[x1][y1])
						c = ar[x1][y1];
					for (i = x1; i <= 1005; i += (i & (-i)))
					{
						for (j = y1; j <= 1005; j += (j & (-j)))
						{
							sa[i][j] -= c;
						}
					}
					ar[x1][y1] -= c;
				}
				else if (!strcmp(s, "M"))
				{
					scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &c);
					x1++;
					y1++;
					x2++;
					y2++;
					if (c >= ar[x1][y1])
						c = ar[x1][y1];
					for (i = x1; i <= 1005; i += (i & (-i)))
					{
						for (j = y1; j <= 1005; j += (j & (-j)))
						{
							sa[i][j] -= c;
						}
					}
					for (i = x2; i <= 1005; i += (i & (-i)))
					{
						for (j = y2; j <= 1005; j += (j & (-j)))
						{
							sa[i][j] += c;
						}
					}
					ar[x1][y1] -= c;
					ar[x2][y2] += c;
				}
			}
		}
	}
	return 0;
}
