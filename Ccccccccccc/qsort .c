#include <stdlib.h>
int comp(const void * p1, const void * p2);

qsort(ar, num, sizeof(...), comp);

int comp(const void * p1, const void * p2)
{
    return *(... *)p1 - *(... *)p2;
}






//对一个二维数组进行排序：int a[1000][2]; 其中按照a[0]的大小进行一个整体的排序，其中a[1]必须和a[0]一起移动交换。
//即第一行和第二行（a[0]和a[1]分别代表第一行和第二行的首地址）。
qsort(a, 1000, sizeof(int)*2, comp);
 
int comp(const void * a,const void * b)
{
    return ((int*)a)[0] - ((int*)b)[0];
}








//对字符串进行排序
int comp(const void * p1,const void * p2)
{
    return strcmp((char*)p2, (char*)p1);
}

int main()
{
    char a[MAX1][MAX2];
    initial(a);
    qsort(a, lenth, sizeof(a[0]), comp);
}
//lenth为数组a的长度











//按结构体中某个关键字排序（对结构体一级排序）：
struct Node
{
    double data;
    int other;
}s[100];

qsort(s, 100, sizeof(s[0]), comp);

int comp(const void * p1,const void * p2)
{
    return (Node*)p2->data > (Node*)p1->data ? 1:-1;
}









//按结构体中多个关键字排序（对结构体多级排序）[以二级为例]：
struct Node
{
    int x;
    int y;
}s[100];
//按照x从小到大排序，当x相等时按y从大到小排序
qsort(s, 100, sizeof(s[0]), comp);
int Comp(const void*p1,const void*p2)
{
    struct Node * c = (Node*)p1;
    struct Node * d = (Node*)p2;
    if(c->x != d->x)
        return c->x - d->x;
    else 
        return d->y - c->y;
}









//对结构体中字符串进行排序：
struct Node
{
    int data;
    char str[100];
}s[100];
//按照结构体中字符串str的字典序排序
qsort(s, 100, sizeof(s[0]), Comp);
int Comp(const void * p1,const void * p2)
{
    return strcmp((Node*)p1->str, (Node*)p2->str);
}

