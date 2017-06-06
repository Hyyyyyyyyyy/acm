#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
using namespace std;
struct node
{
	double stay;
	double right;
	double below;
};
node ar[1010][1010];
double sa[1010][1010];
int N, M;
int main()
{
	int i, j, k, u, n, m, a, b;
	while (scanf("%d %d", &N, &M) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				scanf("%lf %lf %lf", &ar[i][j].stay, &ar[i][j].right, &ar[i][j].below);
			}
		}
		memset(sa, 0, sizeof(sa));
		for (i = N; i >= 1; i--)
		{
			for (j = M; j >= 1; j--)
			{
				if (i == N && j == M)
					continue;
				if (1.0 - ar[i][j].stay < 1.0e-9)
					continue;
				sa[i][j] = (ar[i][j].right*sa[i][j + 1] + ar[i][j].below*sa[i + 1][j] + 2.0) / (1.0 - ar[i][j].stay);
			}
		}
		printf("%.3f\n", sa[1][1]);
	}
	return 0;
}
