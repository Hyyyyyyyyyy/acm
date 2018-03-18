int Find(int x)  
{  
    if(x==fa[x])  
        return x;  
    else  
        return fa[x]=Find(fa[x]);
}  
void Union(int a,int b)
{  
    int x=Find(a);  
    int y=Find(b);
    if(x!=y)
    {  
        if(x>y)  
            fa[x]=y;  
        else  
            fa[y]=x;  
    }  
}  