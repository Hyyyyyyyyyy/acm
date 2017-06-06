#include <stdio.h>
struct busy
{
    int time;
    int happ;
    int rate;
}B[110];
struct areyoubusy
{
    int mrate;
    int mtimetem;
    int mhapptem;
    int n;
    int judge;
    struct busy B[110];
};
int main()
{
    int n, m, i, j, k, u, bag[99999], mtime, c, judge;
    struct areyoubusy A[110];
    while(scanf("%d %d", &c, &mtime) != EOF)
    {
        for(n = 1; n <= c; n++)
        {
            scanf("%d %d", &A[n].n, &A[n].judge);
            A[n].mrate = 0;
            for(m = 1; m <= A[n].n; m++)
            {
                scanf("%d %d", &A[n].B[m].time, &A[n].B[m].happ);
                if(A[n].judge == 0)
                {
                    A[n].B[m].rate = A[n].B[m].happ / A[n].B[m].time;
                    if(A[n].mrate > A[n].B[m].rate)
                    {
                        A[n].mrate = A[n].B[m].rate;
                        A[n].mtimetem = A[n].B[m].time;
                        A[n].mhapptem = A[n].B[m].happ;
                    }
                }
            }
        }
        memset(bag, 0, sizeof(int)*99999);
        for(i = 1; i <= c; i++)
        {
            if(A[i].judge == 0)
            {
                for(k = mtime; k >= A[i].mtimetem; k--)
                    bag[k] = bag[k - A[i].mtimetem]+A[i].mhapptem;
                for(j = 1; j <= A[i].n; j++)
                {
                    if(A[i].B[j].time == A[i].mtimetem)
                        continue;
                    for(k = mtime; k >= A[i].B[j].time; k--)
                    {
                        bag[k] = (bag[k] > bag[k-A[i].B[j].time]+A[i].B[j].happ) ? bag[k]:(bag[k-A[i].B[j].time]+A[i].B[j].happ);
                    }
                }
            }
            if(A[i].judge == 1)
            {
                for(k = mtime; k >= 0; k--)
                {
                    for(j = 1; j <= A[i].n; j++)
                    {
                        bag[k] = (bag[k] > bag[k-A[i].B[j].time]+A[i].B[j].happ) ? bag[k]:(bag[k-A[i].B[j].time]+A[i].B[j].happ);
                    }
                }
            }
            if(A[i].judge == 2)
            {
                for(j = 1; j <= A[i].n; j++)
                {
                    for(k = mtime; k >= A[i].B[j].time; k--)
                    {
                        bag[k] = (bag[k] > bag[k-A[i].B[j].time]+A[i].B[j].happ) ? bag[k]:(bag[k-A[i].B[j].time]+A[i].B[j].happ);
                    }
                }
            }
        }
        if(bag[mtime] == 0)
            printf("-1\n");
        else
            printf("%d\n", bag[mtime]);
    }
    return 0;
}