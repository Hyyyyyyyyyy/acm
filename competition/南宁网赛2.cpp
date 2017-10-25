#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 200000 + 100;
typedef long long ll;
const int INF = 1000000000;
int LIS[maxn];		//记录长度为i的lis的最后一个元素的值
int ar[maxn];
int ld[maxn];			//记录以i结尾的lis的长度
int N;
int Max[maxn];
int erfen(int x, int len)	//找第一个 >= x的值
{
	int l = 1;
	int r = len;
	int mid;
	while (r >= l)
	{
		mid = (l + r) / 2;
		if (LIS[mid] < x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}
int lis()
{
	int i, j, k;
	LIS[1] = ar[1];
	ld[1] = 1;
	int len = 1;
	for (i = 2; i <= N; i++)
	{
		if (ar[i] < 0)
			continue;
		else if (ar[i] > 10000)
		{
			ar[i] -= 10000;
			if (ar[i] >= LIS[len])
			{
                for(j = 1; j <= 5; j++)
				{
                    LIS[++len] = ar[i];
                    ld[i] = len;
                }
			}
			else
			{
                int t = erfen(ar[i], len);
                for(j = 1; j <= 5; j++)
				{
                    LIS[t+j-1] = ar[i];
                    ld[i] = t+j-1;
                }
			}
		}
		else
		{
			if (ar[i] >= LIS[len])
			{
				LIS[++len] = ar[i];
				ld[i] = len;
			}
			else
			{
				int t = erfen(ar[i], len);
				LIS[t] = ar[i];
				ld[i] = t;
			}
		}
	}
	return len;
}
int main()
{
	int i = 0, j, k, u, n, m;
	while (scanf("%d", &ar[++i]) != EOF)
	{
		N = i;
	}
	printf("%d\n", lis());
	return 0;
}