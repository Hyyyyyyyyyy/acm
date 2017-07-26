#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define eps 1e-5

using namespace std;
const int maxn = 1000;
const int maxm = 50000;
const int INF = 0x3f3f3f3f;
typedef long long ll;
struct MaxFlow
{
	int size, n;
	int s, t, k, maxflow, mincost;
	bool vis[maxn];
	int net[maxn], pre[maxn], cur[maxn], dis[maxn];
	std::queue <int> Q;

	int netNode, consumeNode, serverCost;
	//输出
	vector<int> res[maxn];  // p条输出路径
	vector<int> outFlow;  //p条路径的 各自流量
	int outCnt; //记录有多少条输出路径

				//for search path
	int fa[1505];
	int find_flow;
	int p_edge[1505]; //点对应的边的编号
	int ok;
	int find_vis[1505];
	struct EDGE
	{
		int v, cap, cost, next, flow;
		EDGE() {}
		EDGE(int a, int b, int c, int d, int e)
		{
			v = a, cap = b, cost = c, next = d;
			flow = e;
		}
	} E[maxm << 1];



	void init(int _n)
	{
		n = _n, size = 0;
		memset(net, -1, sizeof(net));
	}

	void addedge(int u, int v, int cap, int cost)
	{
		E[size] = EDGE(v, cap, cost, net[u], 0);
		net[u] = size++;
		E[size] = EDGE(u, 0, -cost, net[v], 0);
		net[v] = size++;
	}

	bool adjust()
	{
		int v, min = INF;
		for (int i = 0; i < n; i++)
		{
			if (!vis[i])
				continue;
			for (int j = net[i]; j != -1; j = E[j].next) {
				v = E[j].v;
				if (E[j].cap > E[j].flow)
					if (!vis[v] && dis[v] - dis[i] + E[j].cost < min)
						min = dis[v] - dis[i] + E[j].cost;
			}
		}
		if (min == INF)
			return false;
		for (int i = 0; i <n; i++)
			if (vis[i])
				cur[i] = net[i], vis[i] = false, dis[i] += min;
		return true;
	}

	//找增广路
	int augment(int i, int flow)
	{
		if (i == t)
		{
			mincost += dis[s] * flow;
			maxflow += flow;
			return flow;
		}
		vis[i] = true;

		for (int j = cur[i], v; v = E[j].v, j != -1; j = E[j].next)
			if (E[j].cap > E[j].flow) {

				if (vis[v] || dis[v] + E[j].cost != dis[i]) continue;

				int delta = augment(v, std::min(flow, E[j].cap - E[j].flow));
				if (delta)
				{
					E[j].flow += delta;
					E[j ^ 1].flow -= delta;
					cur[i] = j;
					return delta;
				}
			}

		return 0;
	}


	int zkw(int _s, int _t, int need)
	{
		s = _s, t = _t;

		mincost = maxflow = 0;
		for (int i = 0; i < n; i++) {
			vis[i] = false;
			cur[i] = net[i];
		}

		do
		{
			while (augment(s, INF))
				memset(vis, false, sizeof(vis));
		} while (adjust());
		if (maxflow < need)
			return -1;
		return mincost;
	}


	//------------- for search path

	void update_flow(int minflow, int fa[]) {
		//从s开始
		int cnt = outCnt;
		// printf("cnt=%d: minflow=%d\n",cnt, minflow);
		int u = t;
		while (u != s) {

			//流量更新，减掉minflow
			//  if(p[u]==s) printf("p_edeg=%d ,s.flow=%d ",p_edge[u], edges[p_edge[u]].flow);
			//edges[p_edge[u]].flow -=minflow;
			E[p_edge[u]].flow -= minflow;
			if (u != s) res[cnt].push_back(u);
			//   if(p[u]==s) printf("^^^^ , s.flow=%d \n",edges[p_edge[u]].flow);
			u = fa[u];
		}
		outFlow.push_back(minflow);


		find_flow += minflow;
		outCnt++;
	}


	//cur表示当前点
	void dfs_findPath(int cur, int minflow) {

		if (ok) return;

		//从s正方向找
		if (cur == t) {

			//更新整条路上的 流量
			update_flow(minflow, fa);
			ok = 1;
			return;
		}

		for (int i = net[cur], v; v = E[i].v, i != -1; i = E[i].next) {

			if (E[i].flow <= 0) continue; //反向边不搜索
			if (find_vis[v]) continue;

			fa[v] = cur;
			p_edge[v] = i;
			find_vis[v] = 1;

			dfs_findPath(v, min(minflow, E[i].flow));

			find_vis[v] = 0;

			if (ok) return;

		}

	}




	void search_path() {

		printf("search start\n");
		outCnt = 0;
		for (int i = 0; i<1500; i++)
		{
			res[i].clear();
			outFlow.clear();
		}
		find_flow = 0;
		fa[s] = -1;
		while (find_flow< k) {

			// for(int i=0; i<(int)G[st].size(); i++){
			for (int i = net[s], v; v = E[i].v, i != -1; i = E[i].next) {
				//puts("ss");
				// printf("i=%d, e.flow =%d e.from =%d, e.to =%d\n",i, e.flow , e.flow , e.to);
				fa[v] = s;
				p_edge[v] = i;

				if (E[i].flow>0) {  //搜路径 ,初始为服务点
					ok = 0;
					memset(find_vis, 0, sizeof(find_vis));
					find_vis[s] = 1;
					dfs_findPath(v, INF);
				}


			}
		}
	}

	//输出流量路径
	void OutputPath(string& str) {
		char c[50];

		printf("outCnt = %d\n\n", outCnt);
		sprintf(c, "%d\n\n", outCnt);
		str += c;

		for (int i = 0; i< outCnt; i++) {
			for (int j = (int)res[i].size() - 1; j>0; j--)
			{
				printf("%d ", res[i][j] >= netNode ? (res[i][j] - netNode) : res[i][j]);
				sprintf(c, "%d ", res[i][j] >= netNode ? (res[i][j] - netNode) : res[i][j]);
				str += c;
			}
			printf("%d\n", outFlow[i]);
			sprintf(c, "%d\n", outFlow[i]);
			str += c;
		}
	}
} zkw;




int main() {

	struct MaxFlow ob;
	int cnt;
	int netNode, consumeNode, serverCost;
	int s, t;
	int from, to, cap, cost;
	string str;

	freopen("case1.txt", "r+", stdin);
	// freopen("out.txt", "w+", stdout);

	//网络节点数量 网络链路数量 消费节点数量
	scanf("%d%d%d", &netNode, &cnt, &consumeNode);
	scanf("%d", &serverCost);
	ob.netNode = netNode;
	ob.consumeNode = consumeNode;
	ob.serverCost = serverCost;

	s = netNode + consumeNode;
	t = s + 1;
	ob.init(netNode + consumeNode + 2);

	//网络点
	while (cnt--) {

		scanf("%d%d%d%d", &from, &to, &cap, &cost);
		ob.addedge(from, to, cap, cost);
		ob.addedge(to, from, cap, cost);
	}

	int indx, nodeID;
	ob.k = 0;
	//消费点
	for (int i = 0; i<consumeNode; i++) {
		scanf("%d%d%d", &indx, &nodeID, &cap);
		ob.k += cap;
		//与网络点
		ob.addedge(indx + netNode, nodeID, cap, 0);
		ob.addedge(nodeID, indx + netNode, cap, 0);

		//与t点
		ob.addedge(indx + netNode, t, cap, 0);
	}


	//int servers[]={0,3,22};
	int servers[] = { 6,7,13,17,35,41,48 };
	//int servers[] = {12,18,23,29,31,38,48};
	int serverNum = 7;
	for (int i = 0; i<serverNum; i++) {
		ob.addedge(s, servers[i], INF, 0);
	}

	int ans = ob.zkw(s, t, ob.k);
	printf("ans = %d\n", ans + serverCost*serverNum);
	ob.search_path();
	ob.OutputPath(str);

	return 0;
}
