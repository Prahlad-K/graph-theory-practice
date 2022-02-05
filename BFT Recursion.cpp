#include <iostream>

using namespace std;
int G[100][100];
int n;

void BFT(int current,int *visit)
{
    visit[current]=1;
    for(int i=1;i<=n;i++)
    {
        if(G[current][i]>0&&visit[i]==0)
            {visit[i]=1;
            cout<<i<<" ";}
    }
    for(int i=1;i<=n;i++)
    {
        if(G[current][i]>0)
            BFT(i,visit);
    }
}
int main()
{int start;
    cout<<"Enter the number of vertices:\n";
    cin>>n;
int visit[n];
for(int i=1;i<=n;i++)
    visit[i]=0;

for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
 cin>>G[i][j];}

cout<<"Enter the starting vertex:";
cin>>start;
cout<<start<<" ";
BFT(start,visit);
}
