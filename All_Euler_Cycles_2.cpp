#include <iostream>
using namespace std;
int n,start;
int euler[100];
int index=1;
int counter=1;
int G[100][100];
int prevind=1;
void remove_edge(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(G[i][j]>0)
            G[i][j]=0;
    }
}
void DFT(int current,int *visit)
{
    counter++;
    visit[current]=1;
    for(int i=1;i<=n;i++)
    {if(G[current][i]>0&&visit[i]==0)
    DFT(i,visit);
    }
}
void print(int a[],int s)
{
    for(int i=1;i<s;i++)
cout<<a[i]<<" ";
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
        visit[i]=0;

    if(counter==n+1)
        {counter=1;
        return true;}
    else
        {counter=1;
        return false;}
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

bool iscomplete()
{int ctr1=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(G[i][j]==0)
                ctr1++;
        }
    }
    if(ctr1==n*n+1)
        return true;
    else
        return false;
}


bool eulerian()
{int ctr1=1;
    for(int i=1;i<=n;i++)
    {
        if(degree(i)%2==0)
            ctr1++;
    }
    if(ctr1==n+1)
        return true;
    else
        return false;
}

int ctr=1;
void eulercycle(int current)
{
    euler[index++]=current;
   if(iscomplete())
    {
        print(euler,index);
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(G[current][i]>0)
            {if(!isbridge(current,i))
            {G[current][i]=0;
            G[i][current]=0;
            ctr=1;
            eulercycle(i);}
            else
            ctr++;
            }
        }
        if(ctr==degree(current)+1)
        {for(int i=1;i<=n;i++)
        {
            if(G[current][i]>0)
            {G[current][i]=0;
            G[i][current]=0;
            ctr=1;
            eulercycle(i);
                //break;
            }
        }
        }

    }
}

int main()
{

    cout<<"Enter number of vertices:";
    cin>>n;

    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }
    cout<<"Enter the starting vertex:";
    cin>>start;
    eulercycle(start);
}
