#include <iostream>
using namespace std;
int n,start;

int index=1;
int DFTs[10][100];
int DFTno=1,DFTind=1;
int neighbours[100][100];
int neighbourcount[100];

int startarray[100];int startindex=1;

bool instart(int x)
{
    for(int i=1;i<startindex;i++)
    {
        if(x==startarray[i])
            return true;
    }
    return false;
}

void DFT(int G[10][10],int current,int *visit)
{
cout<<current<<" ";
    visit[current]=1;
    for(int i=1;i<=n;i++)
    {if(G[current][i]>0&&visit[i]==0&&!instart(i))
    DFT(G,i,visit);
}
}

void print(int *a,int n)
{
    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";

}

void printDFTs(int G[10][10],int *visit)
{for(int i=1;i<neighbourcount[startarray[startindex-1]];i++)
    {print(startarray,startindex);
        DFT(G,neighbours[startarray[startindex-1]][i],visit);
        for(int i=0;i<10;i++)
            visit[i]=0;
        cout<<endl;
    }
}

void functioncaller(int G[10][10],int *visit)
{
     for(int i=1;i<neighbourcount[start];i++)
    {
        startarray[startindex++]=neighbours[start][i];
        printDFTs(G,visit);
        cout<<endl;
        startindex--;
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
    int ncount=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(G[i][j]>0&&j!=start)
            {
                neighbours[i][ncount++]=j;
            }
        }
        neighbourcount[i]=ncount;
            ncount=1;
    }

    for(int i=1;i<=n;i++)
    {cout<<i<<":\n";
        for(int j=1;j<neighbourcount[i];j++)
            cout<<neighbours[i][j]<<" ";
        cout<<endl;
    }

    startarray[startindex++]=start;
    functioncaller(G,visit);
    cout<<"This is start array:";
    print(startarray,startindex);
    cout<<endl;
    for(int i=1;i<neighbourcount[1];i++)
    {start=neighbours[1][i];
    startarray[startindex++]=start;
    functioncaller(G,visit);
    startindex--;
    cout<<endl;
    }



    /*cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(visit[i]==0)
            cout<<i<<" is unvisited.\n";
    }*/
}
