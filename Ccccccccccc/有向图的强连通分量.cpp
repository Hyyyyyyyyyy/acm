#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <deque>
using namespace std;
typedef long long ll;
const double eps = 1e-7;
const int INF = 2147483640;
const int maxn = 105;
const int maxm = 10000;
struct TARJAN
{
    struct Edge
    {
        int to;
        int next;
    };
    Edge edge[maxm];
    int tol;
    int Index;
    int top;
    int Sccc;
    int head[maxn];
    int Low[maxn];
    int DFN[maxn];
    int Stack[maxn];
    bool Instack[maxn];
    int Belong[maxn];
    int num[maxn];
    void init()
    {
        tol = 0;
        memset(head, -1, sizeof(head));
    }
    void addedge(int u, int v)
    {
        edge[tol].to = v;
        edge[tol].next = head[u];
        head[u] = tol++;
    }
    void Tarjan(int u)      //将一个环缩成一个点, 多个环相连只算一个环
    {
        int v;
        Low[u] = DFN[u] = ++Index;
        Stack[++top] = u;
        Instack[u] = true;
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].to;
            if(!DFN[v])
            {
                Tarjan(v);
                Low[u] = min(Low[u], Low[v]);
            }
            else if(Instack[v] && Low[u] > DFN[v])
            {
                Low[u] = DFN[v];
            }
        }
        if(Low[u] == DFN[u])
        {
            Sccc++;
            do
            {
                v = Stack[top--];
                Instack[v] = false;
                Belong[v] = Sccc;
                num[Sccc]++;
            }while(v != u);
        }
    }
    void solve(int N)
    {
        memset(DFN, 0, sizeof(DFN));
        memset(Instack, false, sizeof(Instack));
        memset(num, 0, sizeof(num));
        Index = Sccc = top = 0;
        for(int i = 1; i <= N; i++)
        {
            if(!DFN[i])
                Tarjan(i);
        }
    }
};
TARJAN tarjan;
//tarjan.init()
//tarjan.solve(N);
//N  1~N
//Sccc  1~Sccc;
//solve()变化很多
