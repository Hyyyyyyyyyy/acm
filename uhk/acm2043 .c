#include <stdio.h>  
#include <string.h>  
int main()  
{  
    int m, i, l, f1, f2, f3, f4;  
    char psw[51];  
    scanf("%d", &m);  
    while (m--)  
    {  
        scanf("%s", psw);  
        l = strlen(psw);  
        if(l < 8 || l > 16)  
        {  
            printf("NO\n");  
            continue;  
        }  
        f1 = f2 = f3 = f4 = 0;  
        for(i = 0; i < l; i++)  
        {  
            if(psw[i] >= 'A' && psw[i] <= 'Z')  
                f1 = 1;  
            if(psw[i] >= 'a' && psw[i] <= 'z')  
                f2 = 1;  
            if(psw[i] >= '0' && psw[i] <= '9')  
                f3 = 1;  
            if(psw[i] == '~' || psw[i] == '@' || psw[i] == '#' || psw[i] == '$' || psw[i] == '%' || psw[i] == '^')  
                f4 = 1;  
        }  
        if(f1 + f2 + f3 + f4 > 2)  
            printf("YES\n");  
        else  
            printf("NO\n");  
    }  
    return 0;  
}  