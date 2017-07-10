#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <cctype>
#include <queue>
#include <vector>
using namespace std;
const int maxn = 500000 + 100;
typedef long long ll;
int LIS[maxn];		//记录长度为i的lis的最后一个元素的值
int ar[maxn];
int ld[maxn];			//记录以i结尾的lis的长度
int N;
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
		if (ar[i] > LIS[len])
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
	return len;
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d", &N) != EOF)
	{
		for (i = 1; i <= N; i++)
		{
			scanf("%d", &ar[i]);
		}
		printf("%d\n", lis());
	}
	return 0;
}





//n^2的写法
for(i = 1; i <= N; i++)
    ld[i] = 1;
for(i = 1; i <= N; i++)
{
    for(j = 1; j < i; j++)
    {
        if(ar[i] > ar[j] && ld[i] < ld[j] + 1)
        {
            ld[i] = ld[j] + 1;
        }
    }
}