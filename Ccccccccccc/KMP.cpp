#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int maxn = 10000;
char former[maxn], latter[maxn];
int Next[maxn];
void GETnext()      //有优化
{
    int i, j, k;
    int L = strlen(former);
    Next[0] = -1;
    i = 0;
    j = -1;
    while (i < L && j < L)
    {
        if (j == -1 || former[i] == former[j])
        {
            i++;
            j++;
            //优化
            if (former[i] == former[j])
                Next[i] = Next[j];
            else
                Next[i] = j;
            //如果不要优化，这样：
            //Next[i] = j;
        }
        else
            j = Next[j];
    }
}
int KMP()       //返回目标串在主串中出现的次数
{
    int i, j;
    GETnext();
    int L1 = strlen(former);
    int L2 = strlen(latter);
    i = 0;
    j = 0;
    int res = 0;
    while(i < L2)
    {
        if(j == -1 || latter[i] == former[j])
        {
            if(j == L1-1)
            {
                res++;
                j = -1;
            }
            i++;
            j++;
        }
        else
            j = Next[j];
    }
    return res;
}
