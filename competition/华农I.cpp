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
char ar[1000000];
int main()
{
    int i, j, k, u, n, m, a, b, c, v, f, l, r, flag;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &a, &b);
            scanf("%s", ar+1);
            flag = 0;
            for(u = 1; u <= b; u++)
            {
                scanf("%d", &f);
                if(f == 1)
                {
                    scanf("%d %d %d", &l, &r, &v);
                    if(v == 1)
                        for(i = l; i <= r; i++)
                        {
                            ar[i] = 'A';
                        }
                    else
                        for(i = l; i <= r; i++)
                        {
                            ar[i] = 'B';
                        }
                }
                else
                {
                    scanf("%d %d", &l, &r);
                    if(!flag)
                        printf("Case #%d:\n", m);
                    flag = 1;
                    int ss = 0;
                    for(i = l; i <= r; i++)
                    {
                        if(ar[i] == 'B')
                        {
                            ss++;
                        } 
                    }
                    printf("%d\n", ss);
                    i = l;
                    while(ar[i] != '\0')
                    {
                        int L = strlen(ar+1);
                        if(ar[i] == 'B')
                        {
                            for(j = i; j <= L-1; j++)
                            {
                                ar[j] = ar[j+1];
                            }
                            ar[L] = '\0';
                        }
                        i++;
                    }
                }
            }
        }
    }
    return 0;
}
