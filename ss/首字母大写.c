/*����κα����Ű����ո�ĺ��涼Ҫ��д�Ļ�
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

/*�������ֻ�ǿո����Ҫ��д

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

Ȼ����ߵľ��绹��һ������it��s�����s��Ҫ��д
����Ŀǰ��������Ȼ������������

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

��˼���ǵ�һ������||������д��&&

����ǵ����ź������ĸ�Ǵ�д��
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

/*����i=i��ʲô��
����'\0'��ô����д��'\n'
gets(str)
ע����������Ķ���

����toupper isalpha����������С���Ų�Ҫ���
*/ 





/*�����Ŀǰ����߾�����*/

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
