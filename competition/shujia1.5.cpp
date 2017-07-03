#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 110;
struct Node
{
    int x;
    int y;
    int step;
    Node() {}
    Node(int a, int b, int c) : x(a), y(b), step(c) {}
    bool operator < (const Node& p) const
    {
        return step > p.step;
    }
};
Node now, after;
int N, M, K;
int visit[maxn][maxn];
int bfs()
{
    priority_queue<Node>q;
    memset(visit, 0, sizeof(visit));
    now.x = 0;
    now.y = 0;
    now.step = 0;
    visit[0][0] = 1;
    q.push(now);
    while(!q.empty())
    {
        now = q.top();
        q.pop();
        if(now.x == K || now.y == K)
        {
            return now.step;
        }
        if(1)
        {
            if(now.x != 0)
            {
                after.x = 0;
                after.y = now.y;
                after.step = now.step + 1;
                if(!visit[after.x][after.y])
                {
                    q.push(after);
                    visit[after.x][after.y] = 1;
                }
            }
        }
        if(2)
        {
            if(now.y != 0)
            {
                after.x = now.x;
                after.y = 0;
                after.step = now.step + 1;
                if(!visit[after.x][after.y])
                {
                    q.push(after);
                    visit[after.x][after.y] = 1;
                }
            }
        }
        if(3)
        {
            if(now.x != N)
            {
                after.x = N;
                after.y = now.y;
                after.step = now.step + 1;
                if(!visit[after.x][after.y])
                {
                    q.push(after);
                    visit[after.x][after.y] = 1;
                }
            }
        }
        if(4)
        {
            if(now.y != M)
            {
                after.x = now.x;
                after.y = M;
                after.step = now.step + 1;
                if(!visit[after.x][after.y])
                {
                    q.push(after);
                    visit[after.x][after.y] = 1;
                }
            }
        }
        if(5)
        {
            if(now.x != 0 && now.y != M)
            {
                int t = M - now.y;
                if(now.x <= t)
                {
                    after.x = 0;
                    after.y = now.y + now.x;
                }
                else
                {
                    after.x = now.x - t;
                    after.y = M;
                }
                after.step = now.step + 1;
                if(!visit[after.x][after.y])
                {
                    q.push(after);
                    visit[after.x][after.y] = 1;
                }
            }
        }
        if(6)
        {
            if(now.x != N && now.y != 0)
            {
                int t = N - now.x;
                if(now.y <= t)
                {
                    after.x = now.x + now.y;
                    after.y = 0;
                }
                else
                {
                    after.x = N;
                    after.y = now.y - t;
                }
                after.step = now.step + 1;
                if(!visit[after.x][after.y])
                {
                    q.push(after);
                    visit[after.x][after.y] = 1;
                }
            }
        }
    }
    return -1;
}
int main()
{
    int i, j, k, u, n, m, a, b;
    while(scanf("%d %d %d", &N, &M, &K) != EOF)
    {
        int res = bfs();
        if(res != -1)
        {
            printf("%d\n", res);
        }
        else
        {
            printf("impossible\n");
        }
    }
    return 0;
}