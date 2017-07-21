#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
const int maxn = 100000 + 1000;
char former[maxn], latter[maxn];
int exnext[maxn], extend[maxn], Next[maxn];
//Next[i]是former的最长相同前缀，i后缀长度
//exnext[i]是former最长的前缀，和，i后缀的前缀的相同长度
//extend[i]是最长的former前缀，和，latter i后缀的前缀的相同长度
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
void GETexnext()
{
    int i, j, k;
    int L = strlen(former);
    exnext[0] = L;
    i = 1;
    j = 0;
    while (former[i + j] == former[j] && i + j < L)
        j++;
    exnext[1] = j;
    k = 1;
    for (i = 2; i < L; i++)
    {
        int p = k + exnext[k] - 1;
        int l = exnext[i - k];
        if (i + l < p + 1)
        {
            exnext[i] = l;
        }
        else
        {
            j = max(0, p - i + 1);
            while (i + j < L && former[j] == former[i + j])
                j++;
            exnext[i] = j;
            k = i;
        }
    }
}
void GETextend()
{
    int i, j, k;
    int L1 = strlen(former);
    int L2 = strlen(latter);
    GETexnext();
    i = 0;
    j = 0;
    while (j < L1 && j < L2 && former[j] == latter[j])
        j++;
    extend[0] = j;
    k = 0;
    for (i = 1; i < L2; i++)
    {
        int p = extend[k] + k - 1;
        int l = exnext[i - k];
        if (i + l < p + 1)
        {
            extend[i] = l;
        }
        else
        {
            j = max(0, p - i + 1);
            while (j < L1 && i + j < L2 && former[j] == latter[i + j])
                j++;
            extend[i] = j;
            k = i;
        }
    }
}