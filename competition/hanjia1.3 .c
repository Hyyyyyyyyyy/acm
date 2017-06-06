#include <stdio.h>
int main()
{
    int n, m, ip, ic, j, k, xp, yp, x1, y1, x2, y2, cas;
    double S;
    while(scanf("%d", &n) != EOF)
    {
        cas = 0;
        for(m = 1; m <= n; m++)
        {
            cas++;
            scanf("%d", &k);
            xp = 0;
            yp = 0;
            s = 0.0;
            for(u = 1; u <= k; u++)
            {
                
                scanf("%d", &ic);
                if(ic == 1)
                {
                    scanf("%d %d", &x1, y1);
                    S += pow((x1-xp)*(x1-xp) + (y1-yp)*(y1-yp), 0.5);
                    xp = x1;
                    yp = y1;
                    ip = ic;
                }
                else if(ic == 2)
                {
                    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                    S += pow((x1-xp)*(x1-xp) + (y1-yp)*(y1-yp), 0.5);
                    S += pow((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2), 0.5);
                    xp = x2;
                    yp = y2;
                    ip = ic;
                }
                else
                {
                    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                    S += pow((x1-xp)*(x1-xp) + (y1-yp)*(y1-yp), 0.5);
                    S += pow((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2), 0.5);
                    S += pow((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2), 0.5);
                    xp = x2;
                    yp = y2;
                    ip = ic;
                }
            }
            printf("Case %d: %.6lf\n", cas, S);
        }
    }
    return 0;
}