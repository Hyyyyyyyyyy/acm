#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
const int inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 100000007ll;
const int maxn = 1000000 + 100;
const int maxm = 1000000 + 100;
int ar[maxn];
int main()
{
	int i, j, k, N;
	while (scanf("%d", &N) != EOF && N)
	{
		int sum = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
			sum += ar[i];
		}
		if (sum < 0)
		{
			printf("0\n");
			continue;
		}
		int res = 0;
		int front = 1;
		int tail = N;
		sum = 0;
		while (front <= tail)
		{
			sum += ar[front++];
			while (sum < 0)
				sum += ar[tail--];
		}
		sum = 0;
		while (tail > 0)
		{
			if (sum >= 0)
				res++;
			if (sum < 0)
				sum += ar[tail];
			else if (ar[tail] < 0)
				sum = ar[tail];
			tail--;
		}
		printf("%d\n", res);
	}
	return 0;
}