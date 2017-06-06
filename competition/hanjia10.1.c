#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int i, j, k, n, m, u, a, b, c, L, D, S;
    double ang, sum, r, bng;
    while(scanf("%d", &n) != EOF)
    {
    	
        for(m = 1; m <= n; m++)
        {
            scanf("%d %d %d", &L, &D, &S);
            if (D >= S)
			{
				printf("%.2lf\n", 3.141592653589793238462643 * S * S);
				continue;
			}
            ang = atan(2.0 * D / (1.0 * L));
            r = S - pow(1.0*D*1.0*D + 1.0 * L * 1.0 * L/4.0, 0.5);
            if(r <= 0.5 * L)
            {
                sum = 1.0 / 4.0 * S * 1.0 * S * 3.14 + 1.0 / 2.0 * ang * S * S + 1.0 * L / 2.0 * 1.0 * D * 0.5 + 0.5 * r * r * (3.14 - ang);
                printf("%.2lf\n", sum * 2.0);
            }
            else
            {
                bng = acos(1.0 * L / (2.0 * r));
                sum = 1.0 / 4.0 * S * 1.0 * S * 3.14 + 1.0 / 2.0 * ang * S * S + 1.0 * L / 2.0 * 1.0 * D * 0.5 + 0.5 * r * r * (3.14 - ang) - bng * 0.5 * r * r + 0.25 * L * sqrt(r * r - 0.25 * L * L);
                printf("%.2lf\n", sum * 2.0);
            }
        }
    }
    return 0;
}
