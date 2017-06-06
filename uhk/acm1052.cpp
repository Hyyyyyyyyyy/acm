#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
bool comp(int a, int b)
{
    return a > b;
}
int main()
{
    int i, j, k, u, n, m, ar[1010], sa[1010], win, lose, t_slow, t_fast, k_fast, k_slow;
    while(scanf("%d", &n) != EOF && n)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &ar[m]);
        }
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &sa[m]);
        }
        sort(ar+1, ar+1+n, comp);
        sort(sa+1, sa+1+n, comp);
        win = lose = 0;
        t_fast = k_fast = 1;
        t_slow = k_slow = n;
        while(t_slow >= t_fast)
        {
            if(ar[t_slow] > sa[k_slow])
            {
                win++;
                t_slow--;
                k_slow--;
            }
            else if(ar[t_slow] < sa[k_slow])
            {
                lose++;
                t_slow--;
                k_fast++;
            }
            else
            {
                if(ar[t_fast] > sa[k_fast])
                {
                    win++;
                    t_fast++;
                    k_fast++;
                }
                else
                {
                    if(ar[t_slow] < sa[k_fast])
                    {
                        lose++;
                    }
                    t_slow--;
                    k_fast++;
                }
            }
        }
        printf("%d\n", 200*(win - lose));
    }
    return 0;
}