#include <iostream>
#include <queue>
using namespace std;
int n,start;
queue <int> q;

void BFT(int G[10][10],int current,int *visit)
{
    q.push(current);
    visit[current]=1;
    while(q.size()!=0)
    {
        current=q.front();
        cout<<current<<" ";
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(G[current][i]>0&&visit[i]==0)
                {visit[i]=1;q.push(i);}
        }
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

    BFT(G,start,visit);
}
