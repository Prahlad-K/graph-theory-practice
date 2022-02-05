#include <iostream>
using namespace std;

    int n;
    int v;
int c[100];
int ctr=1;

bool unique(int num)
{
    for(int i=1;i<ctr;i++)
    {if(c[i]==num)
       return false;
    }
        return true;
}

void print(int a[],int s)
{if(s!=4)//because this gives C2s, no use.
    {for(int i=1;i<s;i++)
cout<<a[i]<<" ";
cout<<endl;}
}
void cycle(int G[10][10],int a)
{
    if(a==v&&ctr!=2)
    {
    print(c,ctr);

    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(G[a][i]>0)
            {if(unique(i)||i==v)
            {c[ctr++]=i;
            cycle(G,i);
            ctr--;}}
        }

    }
}
int main()
{
    cout<<"Enter number of vertices:";
    cin>>n;
    int G[10][10];
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }

    cout<<"Enter the starting vertex:";
    cin>>v;
    c[ctr++]=v;
  cycle(G,v);
  ctr=0;}

