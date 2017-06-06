#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
#include <deque>
using namespace std;
const int MIN = -100000000;
const int MAX = 100000000;
typedef long long ll;
char ar[1000005];
int main()
{
    int i, j, n, m, u, k, a, b, L, res, doudou, flag;
    char ch;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%s", ar);
            L = strlen(ar);
            doudou = 0;
            res = 0;
            for(i = 0; i < L; i++)
            {
                if(ar[i] == 'A')
                {
                    doudou = 1;
                }
                if(ar[i] == 'B' && doudou == 1)
                {
                    res++;
                    doudou = 0;
                }
            }
            printf("Case #%d:\n%d\n", m, res);
        }

    }
    return 0;
}