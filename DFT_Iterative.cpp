#include <iostream>
using namespace std;
int n,start;
int a[100];
int index=1;

bool allvisited(int *visit)
{
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
            return false;

    }
    return true;
}

bool unique(int x)
{
    for(int i=1;i<index;i++)
    {
        if(a[i]==x)
            return false;
    }
    return true;
}

int giveprev(int x)
{
    for(int i=1;i<index;i++)
    {
        if(a[i]==x)
            return a[i-1];
    }

}

//only for a connected.
void DFT(int G[10][10],int current,int *visit)
{int prev,ctr=0;
    label:
    while(!allvisited(visit))
    {ctr=0;
    if(unique(current))
    {a[index++]=current;}
    visit[current]=1;
    for(int i=1;i<=n;i++)
    {if(G[current][i]>0&&visit[i]==0)
    {current=i;
    goto label;}
    else
        ctr++;
    }
    if(ctr==n)
    current=giveprev(current);
    }
}
int main()
{

    cout<<"Enter number of vertices:";
    cin>>n;
    int G[10][10];
    int visit[n+1];
    for(int i=1;i<=n;i++)
        visit[i]=0;
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }

    cout<<"Enter the starting vertex:";
    cin>>start;

    DFT(G,start,visit);
    cout<<endl;
    for(int i=1;i<index;i++)
        cout<<a[i]<<" ";
}
