#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int maxn = 100000;
struct Trie
{
    int next[maxn][26];
    int sta[maxn];
    int root;
    int CNT;
    char s[100];
    int newnode()
    {
        for(int i = 0; i < 26; i++)
        {
            next[CNT][i] = -1;
        }
        sta[CNT] = 0;
        return CNT++;
    }
    void init()
    {
        CNT = 0;
        root = newnode();
    }
    void insert()
    {
        int i, j, k;
        int now = root;
        int L = strlen(s);
        for(i = 0; i < L; i++)
        {
            if(next[now][s[i] - 'a'] == -1)
            {
                next[now][s[i] - 'a'] = newnode();
            }
            now = next[now][s[i] - 'a'];
        }
        sta[now] = 1;
    }
    int search()
    {
        int i, j, k;
        int now = root;
        int L = strlen(s);
        for(i = 0; i < L; i++)
        {
            now = next[now][s[i] - 'a'];
            if(now == -1)
                break;
        }
        if(now != -1 && sta[now])
            return 1;
        else
            return 0;
    }
};
Trie trie;
//别忘了初始化trie.init()
//插入和查询都用s[]数组