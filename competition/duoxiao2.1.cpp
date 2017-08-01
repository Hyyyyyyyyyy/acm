#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <queue>  
#include <cmath>  
#include <algorithm>  
#include <deque>  
using namespace std;
typedef long long ll;
const int INF = 2147483640;
const int maxn = 80000 + 100;
const int maxm = 200000;
char ar[maxn], sa[maxn];
int main()
{
	int i, j, k, u, n, m, A, B, N;
	while (scanf("%d", &n) != EOF)
	{
		for (m = 1; m <= n; m++)
		{
			int doudou1 = 0;
			int doudou2 = 0;
			scanf("%d %d %d", &N, &A, &B);
			scanf("%s", ar);
			scanf("%s", sa);
			for (i = 0; i < N; i++)
			{
				if (ar[i] == sa[i])
					doudou1++;
				else
					doudou2++;
			}
			if (A + B <= (doudou2 + doudou1 * 2) && doudou2 >= abs(A - B))
				printf("Not lying\n");
			else
				printf("Lying\n");
		}
	}
	return 0;
}

