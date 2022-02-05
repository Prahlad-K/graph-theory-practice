#include <iostream>
using namespace std;

    int n;
    int v;
int c[100];
int ctr=1;
int cycles[100][100];
int cycleno=1;
int cyclesizes[100];
bool unique(int num)
{
    for(int i=1;i<ctr;i++)
    {if(c[i]==num)
        return false;
    }
        return true;

}

void print(int a[],int s)
{for(int i=1;i<s;i++)
cycles[cycleno][i]=a[i];
cyclesizes[cycleno++]=s;
}

void cycle(int G[10][10],int a)
{
for(int i=1;i<=n;i++)
{
    if(G[a][i]==1)
    {
        if(i==v)
        {c[ctr++]=v;
        print(c,ctr);
        ctr--;
        }
        else if(unique(i))
        {c[ctr++]=i;
        cycle(G,i);
        }
    }
    if(a!=v&&i==n)
    ctr--;
    else if(a==v&&i==n)
    return;
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
    cout<<"Enter starting vertex:";
    cin>>v;
    c[ctr++]=v;
  cycle(G,v);

  for(int i=1;i<cycleno;i++)
  {
      for(int j=1;j<cyclesizes[i];j++)
        cout<<cycles[i][j]<<" ";
      cout<<endl;
  }
}
