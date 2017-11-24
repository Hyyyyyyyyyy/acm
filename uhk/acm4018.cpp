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
const int maxn = 100000 + 100;
const int maxm = 1000000 + 100;
char ar[maxn], s[maxn];
int main()
{
    int i, j, n, m, N;
    while(scanf("%d", &N) != EOF)
    {
        for(m = 1; m <= N; m++)
        {
            scanf("%s", ar);
            int L = strlen(ar);
            for(i = 0; i < L; i++)
            {
                if(ar[i] == ':')
                {
                    if(i+1<L && i+2 < L)
                    {
                        if(ar[i+1] == '/' && ar[i+2] == '/')
                        {
                            int cnt = 0;
                            for(j = i+3; ar[j] != '/' && ar[j] != ':'; j++)
                            {
                                s[cnt++] = ar[j];
                            }
                            s[cnt] = 0;
                        }
                    }
                }
            }
            printf("Case #%d: %s\n",m, s );
        }
    }
    return 0;
}