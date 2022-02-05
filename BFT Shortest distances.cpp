#include <iostream>
#include <queue>
using namespace std;
int G[1000][1000];
int n,m;
int visit[100];
int distances[100];
queue <int> q;

void BFT(int current,int *visit)
{ q.push(current);
    visit[current]=1;
    while(q.size()!=0)
    {
        current=q.front();

        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(G[current][i]>0&&visit[i]==0)
                {visit[i]=1;q.push(i);
                 distances[i]=distances[current]+6;}
        }
    }

}
int main()
{int start,q,a,b;
cin>>q;
for(int i=1;i<=q;i++)
{
cin>>n>>m;
for(int i=1;i<=n;i++)
    visit[i]=0;
for(int i=1;i<=n;i++)
    distances[i]=-1;

for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
{G[i][j]=0;G[j][i]=0;}

for(int i=1;i<=m;i++)
{
    cin>>a>>b;
G[a][b]=1;
G[b][a]=1;
}
cin>>start;
distances[start]=0;
BFT(start,visit);
for(int i=1;i<=n;i++)
{if(i!=start)
cout<<distances[i]<<" ";}
cout<<endl;
}
}
