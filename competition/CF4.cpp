//#include<bits/stdc++.h>
//#define rep(i,j,k) for((i)=(j);(i)<=(k);++i)
//#define per(i,j,k) for((i)=(j);(i)>=(k);--i)
//using namespace std;
//typedef long long ll;
//inline void cmin(int &x, int y) { if (y<x)x = y; }
//inline void cmax(int &x, int y) { if (y>x)x = y; }
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//char d[4] = { 'R','L','D','U' };
//const int N = 1005;
//int a[N][N], vis[N][N], ok, swapLR, swapUD, x, y, tx, ty, n, m, i, j; char str[N];
//int inline read() {
//	char ch = getchar(); int z = 0, f = 1;
//	while (ch<'0' || ch>'9') { if (ch == '-')f = -1; ch = getchar(); }
//	while (ch >= '0'&&ch <= '9') { z = z * 10 + ch - '0'; ch = getchar(); }
//	return z*f;
//}
//void dfs(int x, int y) {
//	vis[x][y] = 1; int i, tx, ty;
//	if (a[x][y] == 2) { ok = 1; return; }
//	rep(i, 0, 3) {
//		tx = x + dx[i]; ty = y + dy[i];
//		if (tx>0 && ty>0 && tx <= n && ty <= m && !vis[tx][ty] && a[tx][ty] != 1) {
//			dfs(tx, ty);
//			if (ok) return;
//		}
//	}
//	vis[x][y] = 2;
//}
//int main() {
//	//freopen(".in","r",stdin);
//	//freopen(".out","w",stdout);
//	n = read(); m = read();
//	rep(i, 1, n) {
//		scanf("%s", str + 1);
//		rep(j, 1, m)
//			if (str[j] == '.') a[i][j] = 0;
//			else if (str[j] == '*') a[i][j] = 1;
//			else a[i][j] = 2;
//	}
//	ok = 0; dfs(1, 1);
//	swapLR = swapUD = -1;
//	x = 1; y = 1;
//	while (a[x][y] != 2) {
//		vis[x][y] = 0;
//		rep(i, 0, 3) {
//			tx = x + dx[i];
//			ty = y + dy[i];
//			if (vis[tx][ty] == 1) break;
//		}
//		if (swapLR < 0 && i < 2) {
//			swapLR = 1;
//			puts("R");
//			fflush(stdout);
//			tx = read(); ty = read();
//			if (x == tx && y == ty) {
//				puts("L");
//				fflush(stdout);
//				swap(d[0], d[1]);
//				x = read(); y = read();
//			}
//			else {
//				x = tx; y = ty;
//			}
//		}
//		else if (swapUD < 0 && i >= 2) {
//			swapUD = 1;
//			puts("D");
//			fflush(stdout);
//			tx = read(); ty = read();
//			if (x == tx && y == ty) {
//				puts("U");
//				fflush(stdout);
//				swap(d[2], d[3]);
//				x = read(); y = read();
//			}
//			else {
//				x = tx; y = ty;
//			}
//		}
//		else {
//			putchar(d[i]);
//			puts("");
//			fflush(stdout);
//			x = read(); y = read();
//		}
//	}
//	return 0;
//}