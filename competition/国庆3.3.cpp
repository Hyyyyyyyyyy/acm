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
const int maxn = 1100 + 10;
map<char, int>G;
int dir[4][2] = { -1, 0, 1, 0, 0, -1, 0, 1 };
int N;
struct RA
{
	int x;
	int y;
	int xx;
	int yy;
	int dir;
	int sp;
	int t;
};
RA A, B, T;
int changedir(int n)
{
	if (n == 0)
		return 2;
	if (n == 1)
		return 3;
	if (n == 2)
		return 1;
	if (n == 3)
		return 0;
}
int judge(int n)
{
	if (n > N)
		return 1;
	else if (n < 1)
		return -1;
	else
		return 0;
}

int main()
{
	int i, j, u, n, m, a, b, c, K;
	char s1[5], s2[5];
	G['N'] = 0;
	G['S'] = 1;
	G['W'] = 2;
	G['E'] = 3;
	while (scanf("%d", &N) != EOF && N)
	{
		scanf("%s %d %d", s1, &A.sp, &A.t);
		scanf("%s %d %d", s2, &B.sp, &B.t);
		scanf("%d", &K);
		A.x = 1;
		A.y = 1;
		A.dir = G[s1[0]];
		B.x = N;
		B.y = N;
		B.dir = G[s2[0]];
		A.xx = A.x + dir[A.dir][0] * A.sp;
		A.yy = A.y + dir[A.dir][1] * A.sp;
		if (judge(A.xx) || judge(A.yy))
		{
			A.dir ^= 1;
			if (judge(A.xx) == 1)
				A.xx = 2 * N - A.xx;
			if (judge(A.xx) == -1)
				A.xx = 2-A.xx;
			if (judge(A.yy) == 1)
				A.yy = 2 * N - A.yy;
			if (judge(A.yy) == -1)
				A.yy = 2-A.yy;
		}
		B.xx = B.x + dir[B.dir][0] * B.sp;
		B.yy = B.y + dir[B.dir][1] * B.sp;
		if (judge(B.xx) || judge(B.yy))
		{
			B.dir ^= 1;
			if (judge(B.xx) == 1)
				B.xx = 2 * N - B.xx;
			if (judge(B.xx) == -1)
				B.xx = 2-B.xx;
			if (judge(B.yy) == 1)
				B.yy = 2 * N - B.yy;
			if (judge(B.yy) == -1)
				B.yy = 2-B.yy;
		}
		for (i = 1; i < K; i++)
		{
			A.x = A.xx;
			A.y = A.yy;
			B.x = B.xx;
			B.y = B.yy;
			if (A.x == B.x && A.y == B.y)
			{
				int t = A.dir;
				A.dir = B.dir;
				B.dir = t;
				A.xx = A.x + dir[A.dir][0] * A.sp;
				A.yy = A.y + dir[A.dir][1] * A.sp;
				if (judge(A.xx) || judge(A.yy))
				{
					A.dir ^= 1;
					if (judge(A.xx) == 1)
						A.xx = 2 * N - A.xx;
					if (judge(A.xx) == -1)
						A.xx = 2 - A.xx;
					if (judge(A.yy) == 1)
						A.yy = 2 * N - A.yy;
					if (judge(A.yy) == -1)
						A.yy = 2 - A.yy;
				}
				B.xx = B.x + dir[B.dir][0] * B.sp;
				B.yy = B.y + dir[B.dir][1] * B.sp;
				if (judge(B.xx) || judge(B.yy))
				{
					B.dir ^= 1;
					if (judge(B.xx) == 1)
						B.xx = 2 * N - B.xx;
					if (judge(B.xx) == -1)
						B.xx = 2 - B.xx;
					if (judge(B.yy) == 1)
						B.yy = 2 * N - B.yy;
					if (judge(B.yy) == -1)
						B.yy = 2 - B.yy;
				}
			}
			else
			{
				if (i % A.t == 0)
				{
					A.dir = changedir(A.dir);
				}
				if (i % B.t == 0)
				{
					B.dir = changedir(B.dir);
				}
				A.xx = A.x + dir[A.dir][0] * A.sp;
				A.yy = A.y + dir[A.dir][1] * A.sp;
				if (judge(A.xx) || judge(A.yy))
				{
					A.dir ^= 1;
					if (judge(A.xx) == 1)
						A.xx = 2 * N - A.xx;
					if (judge(A.xx) == -1)
						A.xx = 2 - A.xx;
					if (judge(A.yy) == 1)
						A.yy = 2 * N - A.yy;
					if (judge(A.yy) == -1)
						A.yy = 2 - A.yy;
				}
				B.xx = B.x + dir[B.dir][0] * B.sp;
				B.yy = B.y + dir[B.dir][1] * B.sp;
				if (judge(B.xx) || judge(B.yy))
				{
					B.dir ^= 1;
					if (judge(B.xx) == 1)
						B.xx = 2 * N - B.xx;
					if (judge(B.xx) == -1)
						B.xx = 2 - B.xx;
					if (judge(B.yy) == 1)
						B.yy = 2 * N - B.yy;
					if (judge(B.yy) == -1)
						B.yy = 2 - B.yy;
				}
			}
		}
		printf("%d %d\n", A.xx, A.yy);
		printf("%d %d\n", B.xx, B.yy);
	}
	return 0;
}