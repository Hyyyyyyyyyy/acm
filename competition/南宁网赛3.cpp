#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cmath>
#include <cctype>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int INF = 100000000;
const ll MOD = 1e9 + 7;
const int maxn = 400000 + 100;
const int maxm = 5000000 + 100;
ll M[100];
ll N;
map<string, bool>G;
string S, T;
struct Node
{
	string x;
	ll step;
};
Node now, after;
ll bfs()
{
	ll i, j, k;
	queue<Node>Q;
	now.x = S;
	now.step = 0;
	Q.push(now);
	G[S] = true;
	while (!Q.empty())
	{
		now = Q.front();
		Q.pop();
		if (now.x == T)
			return now.step;
		for (i = 1; i < N; i++)
		{
			after = now;
			swap(after.x[0], after.x[i]);
			if (G.count(after.x) == 0)
			{
				after.step++;
				Q.push(after);
				G[after.x] = true;
			}
		}
	}
	return -1;
}
int main()
{
	ll i, j, k, u, n, m;
	cin >> N;
	for (i = 1; i <= 5; i++)
	{
		G.clear();
		cin >> S >> T;
		cout << bfs() << endl;
	}
	return 0;
}