#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1000010;
int mod;
int visit[maxn];
struct Node
{
	int x;
	int step;
	string ans;
};
Node now, after;
int N, M, K, RES;
bool bfs()
{
	int i, j;
	memset(visit, 0, sizeof(visit));
	now.ans = "";
	after.ans = "";
	queue<Node>q;
	now.x = N;
	now.step = 0;
	visit[(now.x % K + K) % K] = 1;
	q.push(now);
	while (!q.empty())
	{
		now = q.front();
		q.pop();
		if ((now.x % K + K) % K == RES)
			return true;
		if (1)
		{
			after.x = (now.x + M) % mod;
			after.step = now.step + 1;
			after.ans = now.ans + '+';
			if (!visit[(after.x % K + K) % K])
			{
				q.push(after);
				visit[(after.x % K + K) % K] = 1;
			}
		}
		if (2)
		{
			after.x = (now.x - M) % mod;
			after.step = now.step + 1;
			after.ans = now.ans + '-';
			if (!visit[(after.x % K + K) % K])
			{
				q.push(after);
				visit[(after.x % K + K) % K] = 1;
			}
		}
		if (3)
		{
			after.x = (now.x * M) % mod;
			after.step = now.step + 1;
			after.ans = now.ans + '*';
			if (!visit[(after.x % K + K) % K])
			{
				q.push(after);
				visit[(after.x % K + K) % K] = 1;
			}
		}
		if (4)
		{
			after.x = ((now.x % M + M) % M);
			after.step = now.step + 1;
			after.ans = now.ans + '%';
			if (!visit[(after.x % K + K) % K])
			{
				q.push(after);
				visit[(after.x % K + K) % K] = 1;
			}
		}
	}
	return false;
}
int main()
{
	int i, j, k, u, n, m;
	while (scanf("%d %d %d", &N, &K, &M) != EOF && (N != 0 || M != 0 || K != 0))
	{
		RES = ((N + 1) % K + K ) % K;
		mod = K * M;
		if (bfs())
		{
			printf("%d\n", now.step);
			cout << now.ans << endl;
		}
		else
			printf("0\n");
	}
	return 0;
}