#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
typedef struct mouse
{
    int sp;
    int wei;
    int num;
    int father;
}mouse;
mouse arr[1000];
int dp[1000];
int cmp(mouse a,mouse b)
{
    if(a.wei>b.wei)
    {
        return 1;
    }
    /*else if(a.wei==b.wei&&a.sp<b.sp)
    {
        return 1;
    }*/
    else
    {
        return 0;
    }
}
int main()
{
    int i,j,n,N;
    N=0;
    while(scanf("%d%d",&arr[N].wei,&arr[N].sp)!=EOF)
    {
        arr[N].num=N;
        N++;
    }
    sort(arr,arr+N,cmp);
    for(i=0;i<N;i++)
    {
        dp[i]=1;
        arr[i].father=i;
    }
    int huge=1;
    int suo=0;
    for(i=1;i<N;i++)
    {
        int index=i;
        int maxn=dp[i];
        for(j=0;j<i;j++)
        {
            if(arr[i].sp>arr[j].sp&&arr[i].wei<arr[j].wei)
            {
                if(dp[j]+1>maxn)
                {
                    index=j;
                    maxn=dp[j]+1;
                }
            }
        }
        dp[i]=maxn;
        arr[i].father=index;
        if(huge<maxn)
        {
            huge=maxn;
            suo=i;
        }
    }
    printf("%d\n",huge);
    while(arr[suo].father!=suo)
    {
        printf("%d\n",arr[suo].num+1);
        suo=arr[suo].father;
    }
    printf("%d",arr[suo].num+1);
}
