
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N,P;

int consize[100];
int conindex=0;
int index=0;
void DFT(int G[100][100],int current,int *visit)
{
    index++;
    visit[current]=1;
    for(int i=0;i<N;i++)
    {if(G[current][i]>0&&visit[i]==0)
        DFT(G,i,visit);}
}
void connectedcomponents(int G[100][100],int *visit)
{for(int i=0;i<N;i++)
        visit[i]=0;

    for(int i=0;i<N;i++)
    {
        if(visit[i]==0)
            {DFT(G,i,visit);
        consize[conindex++]=index;
        index=0;}

    }
}


int main() {
    cin>>N>>P;
int G[100][100],a,b;
    for(int i=0;i<P;i++)
    {cin>>a>>b;
    G[a][b]=1;
    G[b][a]=1;
    }
   int visit[N];
    int complete[N];
    for(int i=0;i<conindex;i++)
    {
        complete[i]=0;
    }
    connectedcomponents(G,visit);
    int res=0;
    for(int i=0;i<conindex;i++)
    {if(complete[i]==0)
    {for(int j=0;j<conindex;j++)
    {
        if(i!=j&&complete[j]==0)
        res=res+consize[i]*consize[j];
    }
     complete[i]=1;
    }}
    cout<<res;

    return 0;
}
