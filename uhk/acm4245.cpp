#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define foR for
#define for9 for
#define retunr return
#define reutrn return
#define reutnr return
const ll inf = (1 << 31) - 1;
const ll INF = (1ll << 63) - 1;
const double PI = acos(-1.0);
const double eps = 1e-7;
const ll MOD = 1000000007ll;
const ll maxn = 1000 + 100;
const ll maxm = 1000000 + 100;
char S1[maxn];
char S2[maxn];
map<string, string> mp;
int main()
{
	int i, j, k, cas = 1;
	mp.clear();
	mp["minor"] = "major";
	mp["major"] = "minor";
	mp["A#"] = "Bb";
	mp["C#"] = "Db";
	mp["D#"] = "Eb";
	mp["F#"] = "Gb";
	mp["G#"] = "Ab";
	mp["Bb"] = "A#";
	mp["Db"] = "C#";
	mp["Eb"] = "D#";
	mp["Gb"] = "F#";
	mp["Ab"] = "G#";
	while (cin >> S1 >> S2)
	{
		if (strlen(S1) > 1)
		{
			cout << "Case " << cas++ << ": " << mp[S1] << " " << S2 << endl;
		}
		else
		{
			cout << "Case " << cas++ << ": " << "UNIQUE" << endl;
		}
	}
	return 0;
}