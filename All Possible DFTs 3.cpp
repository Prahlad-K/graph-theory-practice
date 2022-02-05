#include <iostream>

using namespace std;
int G[100][100];
int n;
int a[100];
int index=1;

void print()
{
    for(int i=1;i<index;i++)
        cout<<a[i]<<" ";
}


void All_DFTs(int current,int *visit)
{
    a[index++]=current;
    visit[current]=1;
    for(int i=1;i<=n;i++)
    {if(G[current][i]>0&&visit[i]==0)
    All_DFTs(i,visit);
    }

}

int main()
{
cout<<"Enter the number of vertices:";
cin>>n;
int visit[n];
for(int i=1;i<=n;i++)
    visit[i]=0;
for(int i=1;i<=n;i++)
{ for(int j=1;j<=n;j++)
        {cin>>G[i][j];}}
        int start;
cout<<"Enter starting vertex:";
cin>>start;
All_DFTs(start,visit);
print();

}
