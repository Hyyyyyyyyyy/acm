#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int V, K, bestn;
double len[105 * 105], x[105], y[105], tmp[105][105];
int dp[105], sum[105][105], G[105][105];
void dfs(int ns, int dep) {
	int i, j, u, v, cnt;
	if (ns == 0) {
		bestn = max(dep, bestn);
		return;
	}
	for (i = 0; i<ns; i++) {
		u = sum[dep][i];
		if (dep + V - u + 1 <= bestn || dep + dp[u] <= bestn)
			return;
		cnt = 0;
		for (j = i + 1; j<ns; j++) {
			v = sum[dep][j];
			if (G[u][v])
				sum[dep + 1][cnt++] = v;
		}
		dfs(cnt, dep + 1);
	}
}
int judge(double mid) {
	int i, j, ns;
	memset(G, 0, sizeof(G));
	for (i = 1; i <= V; i++)
		for (j = i + 1; j <= V; j++)
			if (tmp[i][j] >= mid)
				G[i][j] = G[j][i] = 1;
	bestn = 0;
	for (i = V; i >= 1; i--) {
		ns = 0;
		for (j = i + 1; j <= V; j++) {
			if (G[i][j])
				sum[1][ns++] = j;
		}
		dfs(ns, 1);
		dp[i] = bestn;
		if (bestn >= K)
			return 1;
	}
	return 0;
}                                               //最大团模板
int main() {                                     //就是转换成二分最短边，将比最短边大
	int i, j, k, l, r, id, ans, mid;                   //的值全部连起来，用最大团判断是否点的
	while (scanf("%d%d", &V, &K) != EOF) {            //个数大于k
		id = 1;
		for (i = 1; i <= V; i++)
			scanf("%lf%lf", &x[i], &y[i]);
		for (i = 1; i <= V; i++) {
			tmp[i][i] = 0;
			for (j = i + 1; j <= V; j++) {
				tmp[i][j] = tmp[j][i] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
				len[id++] = tmp[i][j];
			}
		}                                       //用所有长度排序后二分下标，而不是直接
		sort(len + 1, len + id);                     //二分长度
		l = 1, r = id - 1;
		while (l <= r) {
			mid = (l + r) / 2;
			if (judge(len[mid])) {
				l = mid + 1;
				ans = mid;
			}
			else
				r = mid - 1;
		}
		printf("%.2lf\n", sqrt(len[ans]));
	}
	return 0;
}