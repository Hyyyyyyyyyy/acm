#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
using namespace std;
const int maxn = 10;
int ar[maxn][maxn];
int main()
{
	int i, j, k, u, n, m, doudou;
	while (scanf("%d %d %d %d", &ar[1][1], &ar[1][2], &ar[1][3], &ar[1][4]) != EOF)
	{
		doudou = 0;
		scanf("%d %d %d %d", &ar[2][1], &ar[2][2], &ar[2][3], &ar[2][4]);
		scanf("%d %d %d %d", &ar[3][1], &ar[3][2], &ar[3][3], &ar[3][4]);
		scanf("%d %d %d %d", &ar[4][1], &ar[4][2], &ar[4][3], &ar[4][4]);
		if (ar[1][4])
		{
			if (ar[1][1] || ar[1][2] || ar[1][3] || ar[2][1] || ar[3][2] || ar[4][3])
				doudou = 1;
		}
		if (ar[2][4])
		{
			if (ar[1][3] || ar[2][1] || ar[2][2] || ar[2][3] || ar[3][1] || ar[4][2])
				doudou = 1;
		}
		if (ar[3][4])
		{
			if (ar[1][2] || ar[2][3] || ar[3][1] || ar[3][2] || ar[3][3] || ar[4][1])
				doudou = 1;
		}
		if (ar[4][4])
		{
			if (ar[1][1] || ar[2][2] || ar[3][3] || ar[4][1] || ar[4][2] || ar[4][3])
				doudou = 1;
		}
		if (doudou)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}