#include <iostream>
#include <string>
using namespace std;

// 实现大数相加  结果存放在num中 

void bigIntergerAdd(string &num, string add) {

	int goBit = 0; // 存放进位

				   // 先交换下顺序  加数的位数要比较少
	if (num.length() < add.length()) {

		string tmp = num;
		num = add;
		add = tmp;
	}

	string tmp(num.length() - add.length(), '0');
	add = tmp + add;

	// 利用string的+号特性  不采用逆序相加法 
	int len1 = num.length(), len2 = add.length();
	for (int i = len1 - 1; i >= 0; --i) {

		int tmp = ((num[i] - '0') + (add[i] - '0') + goBit);

		num[i] = tmp % 10 + '0';

		goBit = tmp / 10;
	}

	// 特殊情况处理
	if (goBit != 0)
		num.insert(0, string(1, (char)goBit + '0'));
}
int main()
{
	int i, j;
	string s1, s2;
	cin >> s1 >> s2;
	bigIntergerAdd(s1, s2);
	for (i = 0; i <= s1.size() - 1; i++)
	{
		if (s1[i] != '0')
		{
			break;
		}
	}
	cout << &s1[i] << endl;
	cout << s1 << endl;
	return 0;
}








#include <iostream>
#include <string>
using namespace std; 

// 大数相乘 

string bigIntegerPlus(string res, string plusN) {
    
    string ret; 
    if (res.length()< plusN.length()) {
        
        string tmp = res;
        res = plusN;
        plusN = tmp; 
    }
    
    int len1 = res.length(), len2 = plusN.length();
    for (int i = len2-1; i>=0; --i ) {
        
        string tmp(len1, '0'); // 存放相乘的中间结果 
        int goBit =0;
        for (int j= len1-1; j >=0; --j) {
        
            int mid = (res[j] -'0') * (plusN[i] -'0') + goBit;
            tmp[j] = mid%10 + '0';
            goBit = mid /10;
        }
        if (goBit != 0) 
            tmp.insert(0, string(1,goBit +'0'));
        
        for (int m=0; m< len2 -1-i; ++m)
            tmp.push_back('0'); // 补位  
        
        // 相乘后就相加  大数相加
        if (i == len2-1)
            ret = tmp;
        else {
            
            int goBit2 =0; 
            string s(tmp.length() - ret.length() ,'0');
            ret = s + ret;
            for (int m = tmp.length()-1; m>=0; --m) {
                
                int mid = (tmp[m] -'0')+(ret[m] - '0')  + goBit2;
                ret[m] = mid %10 +'0';
                goBit2 = mid/ 10;    
            }
            
            if (goBit2 != 0) 
                ret.insert(0, string(1,goBit +'0'));
        }     
    } 

    // 去掉前导0
    while (ret.length() >1 && ret[0] == '0')
        ret.erase(0,1);
     
    return ret;    
}
int main()
{
	string s1, s2, res;
	cin >> s1 >> s2;
	res = bigIntegerPlus(s1, s2);
	cout << res << endl;
	return 0;
}
//00000000000000000001546834444444443412332131351313113131313
//00000000000000000000000000000546468468497978945613321515565561233
//845296249875477088332644014107880443737808280124537602414883530808871188929








#include <iostream>
#include <cstring>
using namespace std;

void bigDivision(char *src, int num, char sign) {
	int i, j;
	long long rem = 0; // 存放新余数 
	long long prem = 0; // 原余数
	char  res[10000] = "";
	bool flag = true;
	int k = 0;
	for (i = 0; i< strlen(src); ++i) {

		rem = prem * 10/*向后退一位*/ + src[i] - '0';
		if (rem / num >0 || rem == 0) {

			res[k++] = rem / num + '0';
			prem = rem %num;
			flag = false;
		}
		else {

			prem = rem;
			if (!flag)
				res[k++] = '0';
		}
	}

	if (sign == '%') {

		cout << prem << endl;
		return;
	}
	for (i = 0; i <= strlen(res) - 1; i++)
	{
		if (res[i] != '0')
		{
			break;
		}
	}
	for (j = i; j< k; ++j)
		cout << res[j];
	cout << endl;
}

int main(int argc, char** argv) 
{
	int i, j;
	char src[10000] = "";
	int num;
	char sign;
	while (scanf("%s%d", src, &num) != EOF) 
	{
		bigDivision(src, num, '/');
		bigDivision(src, num, '%');
	}

	return 0;
}














#include <iostream>
#include <string>
using namespace std;

// 求幂  思路: 先变成整数相乘   然后根据小数的位数 结合幂  算出小数点该结果字符串的位置 即可

string bigIntegerPlus(string src, string num) {
    
    string tmp = src;
    for (int i =num.length() -1; i >= 0 ; --i) {
        
        string mid(tmp.length(),'0');
        int goBit =0;
        for (int j =  tmp.length()-1; j >= 0; --j) {
            
            int tm = goBit + (tmp[j] -'0')* (num[i] - '0');
            mid[j] = tm% 10 +'0';
            goBit = tm  /10;
        }
        
        for (int q = num.length()-1; q> i; --q) 
            mid.push_back('0');
        if (goBit != 0) 
            mid.insert(0, string(1, (char)goBit +'0'));

        // 加法运算
        if (i == num.length()-1)
            src = mid;
        else {
        
            goBit =0;
            string s(mid.length() - src.length(), '0');
            src = s + src;
            for (int j = mid.length()-1; j>=0; --j) {
            
                int tm = (mid[j] - '0') +(src[j] - '0') + goBit;
                src[j] = tm %10 + '0';
                goBit = tm /10;
            }

            if (goBit !=0) 
                src.insert(0, string(1, (char)goBit +'0'));
        }    
    }
    return src;
}

int main(int argc, char** argv) {
    
    string str;
    while ( getline(cin, str)) {
        
        // 分割出待积数 和 幂  以及小数点位置
        int i =0;
        int index = 0;// 小数位置
        int count = 0;//幂次数
        string num;
        while ( i< str.length()) {
            
            if ( str[i] != ' ') {
            
                if (str[i] == '.')
                    index = i;
                else
                    num.push_back(str[i]);
                ++i;
                continue;
            }
            while ( !isdigit(str[i])) 
                ++i;
            
            if (i + 1 == str.length())
                count = str[i] - '0';
            else 
                count = (str[i] - '0') * 10 + str[i+1] - '0';        
            break;        
        }
        
        index = num.length() - index;
            
        string res = num;
        for (int i =0; i< count-1; ++i) {
        
            res = bigIntegerPlus( res, num);
        }
        index = index * count;
        
        res.insert(res.length() - index, string(".")); 
        
        while (res.length() >1 && res[0] == '0')
            res.erase(0, 1);
        
        for (int i =res.length()-1; i>=0; --i) {
            
            if (res[i] == '0' )
                res.erase(i, i+1);
            else 
                break;
        }
        cout<< res<< endl;    
    }
    
    return 0;
}