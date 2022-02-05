#include <iostream>
using namespace std;
int m,n;
int setarray[100];
int vertex[100];
int index=1;
int mem;
struct gnode
{int u,v,w;
};

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
}

bool check(int i,int j)
{
    if(findroot(i)==findroot(j))
        return true;
    else
        return false;
}
bool present(int x)
{
    for(int i=1;i<index;i++)
    {
        if(vertex[i]==x)
            return true;
    }
    return false;
}

void sort(gnode G[],int m)
{gnode temp;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(G[i].w<G[j].w)
            {temp=G[i];
            G[i]=G[j];
            G[j]=temp;
            }
        }
    }

}

int main()
{cout<<"Enter the number of vertices:";
cin>>n;
for(int i=1;i<=n;i++)
setarray[i]=0;
cout<<"Enter the number of edges:";
cin>>m;

struct gnode G[m];
for(int i=1;i<=m;i++)
{
    cin>>G[i].u>>G[i].v>>G[i].w;
}


int minedge;
int a,b;
int counter=0;

sort(G,m);
int i=1;
while(i<=m)
{
    a=G[i].u;b=G[i].v;
cout<<a<<"a "<<b<<"b\n";
if(!check(a,b))//check for cycles
{union_nums(a,b);}
i++;
}//correct algorithm.
cout<<"Minimum spanning tree:\n";
for(int i=1;i<=n;i++)
    cout<<i<<" "<<setarray[i]<<endl;
}
