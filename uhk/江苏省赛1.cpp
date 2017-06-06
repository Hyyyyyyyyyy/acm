#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <cctype>
#include <cmath>
using namespace std;
char s[300], ss[300], sss[100];
char ar[10000];
map<char, char*>q;
int main()
{
    q['A'] = q['a'] = ".-";
    q['B'] = q['b'] = "-...";
    q['C'] = q['c'] = "-.-.";
    q['D'] = q['d'] = "-..";
    q['E'] = q['e'] = ".";
    q['F'] = q['f'] = "..-.";
    q['G'] = q['g'] = "--.";
    q['H'] = q['h'] = "....";
    q['I'] = q['i'] = "..";
    q['J'] = q['j'] = ".---";
    q['K'] = q['k'] = "-.-";
    q['L'] = q['l'] = ".-..";
    q['M'] = q['m'] = "--";
    q['N'] = q['n'] = "-.";
    q['O'] = q['o'] = "---";
    q['P'] = q['p'] = ".--.";
    q['Q'] = q['q'] = "--.-";
    q['R'] = q['r'] = ".-.";
    q['S'] = q['s'] = "...";
    q['T'] = q['t'] = "-";
    q['U'] = q['u'] = "..-";
    q['V'] = q['v'] = "...-";
    q['W'] = q['w'] = ".--";
    q['X'] = q['x'] = "-..-";
    q['Y'] = q['y'] = "-.--";
    q['Z'] = q['z'] = "--..";
    q['1'] = ".----";
    q['2'] = "..---";
    q['3'] = "...--";
    q['4'] = "....-";
    q['5'] = ".....";
    q['6'] = "-....";
    q['7'] = "--...";
    q['8'] = "---..";
    q['9'] = "----.";
    q['0'] = "-----";
    q['.'] = "="; q['-'] = "===";
 
    int i, j, k, u, n, m, a, b, c, h, cnt;
    while (scanf("%d", &n) != EOF)
    {
        for (m = 1; m <= n; m++)
        {
            cnt = 0;
            memset(ar, 0, sizeof(ar));
            scanf("%d", &k);
            for (u = 1; u <= k; u++)
            {
                scanf("%s", s);
                for (i = 0; s[i] != '\0'; i++)
                {
                    strcpy(sss, q[s[i]]);
                    for (j = 0; sss[j] != '\0'; j++)
                    {
                        if (sss[j] == '.')
                        {
                            ar[cnt++] = '=';
                        }
                        else
                        {
                            ar[cnt++] = '=';
                            ar[cnt++] = '=';
                            ar[cnt++] = '=';
                        }
                        ar[cnt++] = '.';
                    }
                    cnt--;
                    ar[cnt++] = '.';
                    ar[cnt++] = '.';
                    ar[cnt++] = '.';
                }
                cnt -= 3;
                ar[cnt++] = '.';
                ar[cnt++] = '.';
                ar[cnt++] = '.';
                ar[cnt++] = '.';
                ar[cnt++] = '.';
                ar[cnt++] = '.';
                ar[cnt++] = '.';
            }
            cnt -= 7;
            ar[cnt] = '\0';
            printf("Case #%d: %s\n", m, ar);
        }
    }
    return 0;
}
