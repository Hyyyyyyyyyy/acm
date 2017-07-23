#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int maxn = 1000 + 100;
int N, M;
char former[maxn], latter[maxn];
int exnext[maxn], extend[maxn];
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
struct Node
{
    char s[1010];
    int w;
};
Node node[1010];
int main()
{
    int i, j, k, u, n, m, a, b;
    while(scanf("%d", &n) != EOF)
    {
        scanf("%d", &N);
        for(i = 1; i <= N; i++)
        {
            scanf("%s %d", node[i].s, &node[i].w);
        }
        scanf("%d", &M);
        for(i = 1; i <= M; i++)
        {
            scanf("%d", &a);
            if(a == 2)
            {
                scanf("%d", &b);
                int res = 0;
                for(j = 1; j <= N; j++)
                {
                    if(node[j].w > node[b].w)
                        continue;
                    if(j == b)
                    {
                        res++;
                        continue;
                    }
                    strcpy(former, node[b].s);
                    strcpy(latter, node[j].s);
                    GETextend();
                    int L1 = strlen(former);
                    int L2 = strlen(latter);
                    if(extend[L2-L1] == L1)
                        res++;
                }
                printf("%d\n", res);
            }
            else
            {
                scanf("%d %d", &a, &b);
                node[a].w = b;
            }
        }
    }
    return 0;
}