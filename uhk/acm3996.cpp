#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
const ll INF = 10000000000000;
const int maxn = 5000;
const int maxm = 400010;
struct ISAP
{
    struct Edge
    {
        int to;
        int next;
        ll cap;
        ll flow;
    };
    Edge edge[maxm];
    int tol;
    int head[maxn];
    int gap[maxn];
    int dep[maxn];
    int cur[maxn];
    int S[maxn];
    int start;
    int end;
    int N;
    int M;
    void init()
    {
        tol = 0;
        memset(head, -1, sizeof(head));
    }
    void addedge(int u, int v, ll w, ll rw = 0)
    {
        edge[tol].to = v;
        edge[tol].cap = w;
        edge[tol].flow = 0;
        edge[tol].next = head[u];
        head[u] = tol++;
        edge[tol].to = u;
        edge[tol].cap = rw;
        edge[tol].flow = 0;
        edge[tol].next = head[v];
        head[v] = tol++;
    }
    void bfs()
    {
        int i, j;
        queue<int>q;
        memset(dep, -1, sizeof(dep));
        memset(gap, 0, sizeof(gap));
        gap[0] = 1;
        dep[end] = 0;
        q.push(end);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (i = head[u]; i != -1; i = edge[i].next)
            {
                int v = edge[i].to;
                if (dep[v] != -1)
                    continue;
                dep[v] = dep[u] + 1;
                gap[dep[v]]++;
                q.push(v);
            }
        }
    }
    ll max_flow()
    {
        int i, j;
        bfs();
        memcpy(cur, head, sizeof(head));
        int top = 0;
        int u = start;
        ll ans = 0;
        while (dep[start] < N)
        {
            if (u == end)
            {
                int Min = INF;
                int inser;
                for (i = 0; i < top; i++)
                {
                    if (Min > edge[S[i]].cap - edge[S[i]].flow)
                    {
                        Min = edge[S[i]].cap - edge[S[i]].flow;
                        inser = i;
                    }
                }
                for (i = 0; i < top; i++)
                {
                    edge[S[i]].flow += Min;
                    edge[S[i] ^ 1].flow -= Min;
                }
                ans += Min;
                top = inser;
                u = edge[S[top] ^ 1].to;
                continue;
            }
            bool flag = false;
            int v;
            for (i = cur[u]; i != -1; i = edge[i].next)
            {
                v = edge[i].to;
                if (edge[i].cap - edge[i].flow && dep[v] == dep[u] - 1)
                {
                    flag = true;
                    cur[u] = i;
                    break;
                }
            }
            if (flag)
            {
                S[top++] = cur[u];
                u = v;
                continue;
            }
            int Min = N;
            for (i = head[u]; i != -1; i = edge[i].next)
            {
                if (edge[i].cap - edge[i].flow && dep[edge[i].to] < Min)
                {
                    Min = dep[edge[i].to];
                    cur[u] = i;
                }
            }
            gap[dep[u]]--;
            if (!gap[dep[u]])
                return ans;
            dep[u] = Min + 1;
            gap[dep[u]]++;
            if (u != start)
                u = edge[S[--top] ^ 1].to;
        }
        return ans;
    }
};
ISAP isap;
//注意要给 isap.start  isap.end  isap.N(包括源点和汇点) 赋值！和 初始化isap.init()
//双向边直接addedge两次就行了
//maxm是边数的2倍！   数组开小了会TLE

ll sum;
int main()
{
    int i, j, n, m, N, M, K, k, a, b;
    scanf("%d", &n);
    {
        for (m = 1; m <= n; m++)
        {
            scanf("%d", &K);
            isap.init();
			sum = 0;
			isap.start = 0;
			isap.end = K * 25 + 1;
			isap.N = K * 25 + 2;
            for (k = 1; k <= K; k++)
            {
                scanf("%d", &N);
                for (i = 1; i <= N; i++)
                {
                    scanf("%lld %lld %d", &a, &b, &M);
                    ll t = b - a;
                    if (t > 0)
                    {
                        sum += t;
                        isap.addedge(0, (k-1)*25+i, t);
                    }
                    else
                    {
                        isap.addedge((k-1)*25+i, isap.end, -t);
                    }
                    for (j = 1; j <= M; j++)
                    {
                        scanf("%d %d", &a, &b);
                        isap.addedge((k-1)*25+i, (a-1)*25+b, INF);
                    }
                }
            }
            printf("Case #%d: %lld\n", m, sum - isap.max_flow());
        }
    }
    return 0;
}