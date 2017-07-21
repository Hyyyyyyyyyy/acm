#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int maxn = 10000;
char former[maxn], latter[maxn];
int Next[maxn];
void GETnext()
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
            if (former[i] == former[j])
                Next[i] = Next[j];
            else
                Next[i] = j;
        }
        else
            j = Next[j];
    }
}
int KMP()
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
