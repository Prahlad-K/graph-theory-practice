#include <iostream>
using namespace std;
int n,start;
int arr[100];
int index=1;

void print()
{
    for(int i=1;i<index;i++)
        cout<<arr[i]<<" ";
        cout<<endl;
}
void DFT(int G[10][10],int current,int *visit)
{

    arr[index++]=current;
     visit[current]=1;
    if(index==n+1)
        {print();}
    for(int i=1;i<=n;i++)
    {if(G[current][i]>0&&visit[i]==0)
    {DFT(G,i,visit);
    visit[i]=0;
    index--;
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

    DFT(G,start,visit);
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
            cout<<i<<" is unvisited.\n";
    }

}
