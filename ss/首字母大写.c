/*如果任何标点符号包括空格的后面都要大写的话
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	char str[1000];
	int i;
	gets(str);
	str[0]=toupper(str[0]);
	for(i=1;str[i]!='\0';i++)
		if(ispunct(str[i-1])||str[i-1]==' '&&isalpha(str[i]))
		str[i]=toupper(str[i]);
	puts(str);
	return 0;
}*/

/*如果仅仅只是空格后面要大写

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	char str[1000];
	int i;
	gets(str);
	str[0]=toupper(str[0]);
	for(i=1;str[i]!='\0';i++)
		if(str[i-1]==' '&&isalpha(str[i]))
		str[i]=toupper(str[i]);
	puts(str);
	return 0;
}

然而最高的境界还有一个就是it’s后面的s不要大写
但是目前我做不到然后我又做到了

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char str[100];
	int i;
	gets(str);
	str[0]=toupper(str[0]);
	for(i=1;str[i]!='\0';i++)
	{
		if(ispunct(str[i-1])||str[i-1]==' '&&isalpha(str[i]))
			str[i]=toupper(str[i]);
		if(str[i-1]=='\'')
			str[i]=tolower(str[i]);
	}
	puts(str);
	return 0;
}

反思就是第一个程序||不可以写作&&

这个是单引号后面的字母是大写的
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char str[1000];
	int i;
	gets(str);
	str[0]=toupper(str[0]);
	for(i=i;str[i]!='\0';i++)
		if(ispunct(str[i-1])||str[i-1]==' '&&isalpha(str[i]))
			str[i]=toupper(str[i]);
	puts(str);
	return 0;
	

}*/ 

/*首先i=i是什么鬼
还有'\0'怎么可以写成'\n'
gets(str)
注意了括号里的东西

还有toupper isalpha里的括号里的小括号不要落掉
*/ 





/*这就是目前的最高境界了*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char str[100];
	int i;
	gets(str);
	str[0]=toupper(str[0]);
	for(i=1;str[i]!='\0';i++)
	{
		if(ispunct(str[i-1])&&isalpha(str[i]))
			str[i]=toupper(str[i]);
		if(str[i-1]==' '&&str[i]=='i')
			str[i]=toupper(str[i]);
		if(str[i-1]=='\'')
			str[i]=tolower(str[i]);
	}
	puts(str);
	return 0;
}
