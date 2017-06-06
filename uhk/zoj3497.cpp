#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
struct node
{
	long long int ar[50][50];
};
node temp, res, start, temp1;
node multiply(node a, node b, int r, int c);
int main()
{
	int i, j, k, u, n, m, a, b, c, t, doudou;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	while (scanf("%d", &n) != EOF)
	{
		getchar();
		for (m = 1; m <= n; m++)
		{
			scanf("%d %d", &a, &b);
			getchar();
			memset(start.ar, 0, sizeof(start.ar));
			c = a * b;
			for (i = 1; i <= a; i++)
			{
				for (j = 1; j <= b; j++)
				{
					scanf("((%d,%d),(%d,%d),(%d,%d),(%d,%d))", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4); 
					getchar();
					if (i == a && j == b)
						continue;
					start.ar[(i - 1)*b + j][(x1 - 1)*b + y1] = 1;
					start.ar[(i - 1)*b + j][(x2 - 1)*b + y2] = 1;
					start.ar[(i - 1)*b + j][(x3 - 1)*b + y3] = 1;
					start.ar[(i - 1)*b + j][(x4 - 1)*b + y4] = 1;
				}
			}
			scanf("%d", &k);
			getchar();
			for (u = 1; u <= k; u++)
			{
				memset(res.ar, 0, sizeof(res.ar));
				for (i = 1; i <= c; i++)
					res.ar[i][i] = 1;
				temp1 = start;
				scanf("%d", &t);
				getchar();
				while (t)
				{
					if (t % 2)
					{
						res = multiply(temp1, res, c, c);
					}
					temp1 = multiply(temp1,temp1, c, c);
					t /= 2;
				}
				//for (i = 1; i <= c;i++)
				//{
				//	for (j = 1; j <= c; j++)
				//	{
				//		printf("%d ", res.ar[i][j]);
				//	}
				//	putchar('\n');
				//}
				if (!res.ar[1][c])
					printf("False\n");
				else
				{
					doudou = 0;
					for (i = 1; i < c; i++)
					{
						if (res.ar[1][i])
						{
							doudou = 1;
							break;
						}
					}
					if (doudou)
						printf("Maybe\n");
					else
						printf("True\n");
				}
			}
			getchar();
			putchar('\n');
		}
	}
	return 0;
}
node multiply(node a, node b, int r, int c)
{
	int i, j, k;
	memset(temp.ar, 0, sizeof(temp.ar));
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			for (k = 1; k <= c; k++)
			{
				temp.ar[i][j] += a.ar[i][k] * b.ar[k][j];
			}
		}
	}
	return temp;
}
