#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
int main()
{
    int i, j, k, u, a, b, c, n, m, p, q, set[1010], sum;
    while(scanf("%d", &n) != EOF)
    {
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d", &p, &q);
            for(i = 0; i <= p; i++)
                set[i] = i;
            for(i = 1; i <= q; i++)
            {
                scanf("%d %d", &a, &b);
                while(a != set[a])
                    a = set[a];
                while(b != set[b])
                    b = set[b];
                if(a != b)
                    set[b] = a;
            }
            sum = 0;
            for(i = 1; i <= p; i++)
                if(set[i] == i)
                    sum++;
            printf("%d\n", sum);
        }
    }
    return 0;
}