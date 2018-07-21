#include <stdio.h>
#include <string.h>
inline int min(int a,int b){return a>b?b:a;}
struct edge
{
    int v,next;
    edge(int d=0,int n=-1):v(d),next(n){}
    void set(int d,int n){v=d;next=n;}
}data[500*2001];
int head[1024],hn;
void adde(int a,int b)
{
    data[hn].set(b,head[a]);
    head[a]=hn++;
}
int n;
int b[501][501];
int dfn[1024],low[1024],sta[1024],belong[1024];
bool ifin[1024];
int top,group,dep;
void tarjan(int u)
{
    dfn[u]=low[u]=++dep;
    sta[++top]=u;
    ifin[u]=true;
    for (int i=head[u];i!=-1;i=data[i].next)
    {
        int v=data[i].v;
        if (!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        } else
        {
            if (ifin[v]) low[u]=min(low[u],dfn[v]);
        }
    }
    if (dfn[u]==low[u])
    {
        int j;
        ++group;
        do
        {
            j=sta[top--];
            belong[j]=group;
            ifin[j]=false;
        } while (u!=j);
    }
}
void init()
{
    hn=dep=group=0;
    top=-1;
    memset(head,-1,sizeof head);
    memset(dfn,0,sizeof dfn);
    memset(ifin,false,sizeof ifin);
}
bool judge()
{
    for (int i=0;i<n;++i)
        if (belong[i]==belong[i+n]) return false;
    return true;
}
bool solve()
{
    for (int i=0;i<n;++i)
        for (int j=i;j<n;++j)
    {
        if (i==j && b[i][j]) return false;
        if (b[i][j]!=b[j][i]) return false;
    }
    for (int k=0;k<31;++k)
    {
        init();
        for (int i=0;i<n;++i)
            for (int j=i;j<n;++j)
        {
            int m=b[i][j]&(1<<k);
            if (i==j) continue;
            if (i&1 && j&1) // |
            {
                if (m)
                {
                    adde(i,j+n);
                    adde(j,i+n);
                } else
                {
                    adde(i+n,i);
                    adde(j+n,j);
                }
            } else if (!(i&1) && !(j&1)) //&
            {
                if (m)
                {
                    adde(i,i+n);
                    adde(j,j+n);
                } else
                {
                    adde(i+n,j);
                    adde(j+n,i);
                }
            } else   // ^
            {
                if (m)
                {
                    adde(i,j+n);
                    adde(j,i+n);
                    adde(j+n,i);
                    adde(i+n,j);
                } else  //==
                {
                    adde(i,j);
                    adde(j,i);
                    adde(i+n,j+n);
                    adde(j+n,i+n);
                }
            }
        }
        for (int i=0;i<(n<<1);++i)
            if (!dfn[i]) tarjan(i);
        if (!judge()) return false;
    }
    return true;
}
int main()
{
    while (~scanf("%d",&n))
    {
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
              scanf("%d",&b[i][j]);
        if (solve()) puts("YES"); else puts("NO");
    }
}