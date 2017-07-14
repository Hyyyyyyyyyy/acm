#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
const int maxn = 10000 + 10;
int grundy[maxn];       //记录sg值     初始化-1
int step[110];          //step记录的是可以取的数目
int N;
int getgrundy(int x)
{
    if (grundy[x] != -1)
        return grundy[x];
    int i, j;
    int visit[110];
    memset(visit, 0, sizeof(visit));
    for (i = 1; i <= N; i++)
    {
        if (step[i] <= x)
        {
            visit[getgrundy(x - step[i])] = 1;
        }
        // else
        //     break;
    }
    int res = 0;
    while (visit[res])
        res++;
    grundy[x] = res;
    return res;
}





int sa[maxn];       //每堆的个数
int step[maxn];
int grundy[maxn];
int N;      //step数组的元素个数，即可以走的步长
void getgrundy()
{
	int i, j;
    int visit[maxn];
	grundy[0] = 0;
	int maxr = *max_element(sa+1, sa+1+cnt);			//这个也可以在读入后使用写为 int maxr = *max_element(sa+1, sa+1+cnt);
	for (i = 1; i <= maxr; i++)
	{
		memset(visit, 0, sizeof(visit));
		for (j = 1; j <= N; j++)
		{
			if(step[j] <= i)
                visit[grundy[i - step[j]]] = 1;
		}
		int res = 0;
		while (visit[res])
			res++;
		grundy[i] = res;
	}
}