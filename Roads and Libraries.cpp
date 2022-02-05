#include <iostream>

using namespace std;

long setarray[100000];
long vertex[100000];
long index=1;

long findroot(long i)
{
    if(setarray[i]==0)
        return i;
    else
        return(findroot(setarray[i]));
}

void union_nums(long x,long y)
{
    if(setarray[x]==0)
        setarray[x]=y;
    else if(setarray[y]==0)
        setarray[y]=x;
    else
        setarray[findroot(x)]=y;
}

bool check(long x,long y)
{
    if(findroot(x)==findroot(y))
        return true;
    else
        return false;
}

bool present(int x)
{
    for(long i=1;i<index;i++)
    {
        if(vertex[i]==x)
            return true;
    }
    return false;
}

void krushkal(long *G[],long n,long m)
{long x,y;
long counter=1;
while(counter!=m+1)
{ for(long i=1;i<=n;i++)
    {for(long j=1;j<=n;j++)
        {if(G[i][j]>0)
        {x=i;y=j;}
        }
    }
if(!check(x,y))
{union_nums(x,y);
}
vertex[index++]=x;
vertex[index++]=y;
G[x][y]=-1;
G[y][x]=-1;
counter++;
}

}


int main()
{long q,n,m,clib,croad,a,b,ans=0;
    cin>>q;
    for(int a1=1;a1<=q;a1++)
    {ans=0;
    cin>>n>>m>>clib>>croad;
    long *G[n];
    for(long i=1;i<=n;i++)
        G[i]=new long[n];
    for(long i=1;i<=m;i++)
    {cin>>a>>b;
        G[a][b]=croad;
        G[b][a]=croad;
    }

    if(clib<croad||m==0)
        cout<<clib*n<<endl;
    else
    {
        krushkal(G,n,m);
        for(long i=1;i<=n;i++)
            {if(setarray[i]!=0)
                ans=ans+croad;
            else
                ans=ans+clib;}
            cout<<ans<<endl;
    }
    }
}
