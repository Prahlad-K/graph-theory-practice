#include <iostream>
using namespace std;

int setarray[100];
struct gnode
{
    int w;
    int u,v;

}g[10];


int findroot(int i)
{
    if(setarray[i]==0)
        return i;
    else
        return findroot(setarray[i]);
}

void union_nums(int a,int b)
{
    if(setarray[a]==0)
        setarray[a]=b;
    else if(setarray[b]==0)
        setarray[b]=a;
    else
        setarray[findroot(b)]=a;

}

bool check(int i,int j)
{
    if(findroot(i)==findroot(j))
        return true;
            else
        return false;
}


int main()
{for(int i=1;i<11;i++)
setarray[i]=0;

for(int i=1;i<11;i++)
{
    cin>>g[i].u>>g[i].v>>g[i].w;
}

int i=1;
while(i<=6)
{
    struct gnode minw;
     minw.w=10;
    for(int j=1;j<11;j++)
    {
        if(minw.w>g[j].w)
            minw=g[j];
    }
    if(!check(minw.u,minw.v))
    {minw.w=1000;
    union_nums(minw.u,minw.v);}
    i+=2;
}

for(int i=1;i<=6;i++)
 cout<<setarray[i]<<" ";
}
