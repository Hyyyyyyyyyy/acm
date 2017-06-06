#include <stdlib.h>
#include <stdio.h>
int main(void)
{
    int number=123456;
    char string[25];
    itoa(number,string,10);
    printf("integer=%d string=%s\n",number,string);
    return 0;
}
//char*itoa(int value,char*string,int radix);

//atoi
//int atoi(const char *nptr);
/*atoi( ) 函数会扫描参数 nptr字符串，跳过前面的空白字符（例如空格，tab缩进等，可以通过isspace( )函数来检测），
直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时('\0')才结束转换，并将结果返回。
如果 nptr不能转换成 int 或者 nptr为空字符串，那么将返回 0  */
#include <stdlib.h>
#include <stdio.h>
 
int main(void)
{
    int n;
    char *str = "12345.67";
    n = atoi(str);
    printf("n=%d\n",n);
    return 0;
}
