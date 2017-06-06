#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <deque>
#include <cmath>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100000000;
const int MIN = -100000000;
int main()
{
    int i, j, k, u, a, b, c, n, m, N, M;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d", &k);
            N = M = 0;
            for(u = 1; u <= k; u++)
            {
                scanf("%d", &a);
                if(a == 1)
                {
                    N++;
                }
                else if(a == 2)
                {
                    M++;
                }
                else if(a == 3)
                {
                    N++;
                    M++;
                }
                else
                {
                    N--;
                    M--;
                }
            }
            if(N > M)
            {
                printf("Kobayashi\n");
            }
            else if(N < M)
            {
                printf("Tohru\n");
            }
            else
             printf("Draw\n");
        }
    }
    return 0;
}