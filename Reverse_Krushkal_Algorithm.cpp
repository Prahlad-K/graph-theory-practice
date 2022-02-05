#include <iostream>
using namespace std;
int n,m;
int G[100][100];
int setarray[100];
int vertex[100];
int index=1;
void DFT(int current,int *visit)
{
    visit[current]=1;
        for(int i=1;i<=n;i++)
    {if(G[current][i]>0&&visit[i]==0)
    DFT(i,visit);
    }
}

int degree(int i)
{int s=0;
    for(int j=1;j<=n;j++)
    {
        s=s+G[j][i];
    }
    return s;
}

bool isconnected()
{ int visit[n+1];
    for(int i=1;i<=n;i++)
        visit[i]=0;
    DFT(1,visit);
    for(int i=1;i<=n;i++)
        {if(visit[i]==0)
        {return false;}}
        return true;
}

bool isbridge(int current,int i)
{
G[current][i]=0;
G[i][current]=0;
bool con=isconnected();
G[current][i]=1;
G[i][current]=1;
return !con;
}

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
int main()
{cout<<"Enter the number of vertices:";
cin>>n;
cout<<"Enter the number of edges:";
cin>>m;
for(int i=1;i<=n;i++)
setarray[i]=0;

for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++)
        cin>>G[i][j];

int maxedge;
int a,b;
int counter=0;
while(counter!=m+1)
{maxedge=0;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        if(G[i][j]>maxedge)
        {a=i;b=j;
            maxedge=G[i][j];
        }
    }
}

if(!isbridge(a,b))
{
    G[a][b]=0;
    G[b][a]=0;
}
counter=counter+1;
}
cout<<"Minimum Spanning tree:\n";
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {if(G[i][j]>0&&i<j)
        cout<<i<<" "<<j<<endl;
    }

}
}
