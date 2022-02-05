#include <iostream>
using namespace std;

    int n;
    int v;
int c[100];
int ctr=0;
int cycles[200][200];
bool unique(int num)
{int p=0;
    for(int i=0;i<ctr;i++)
    {if(c[i]!=num)
        p++;
    }
    if(p==ctr-1)
        return true;
    else
        return false;
}
int k=0;int sizes[10];
void store(int c[],int ctr)
{for(int i=0;i<ctr;i++)
cycles[k][i]=c[i];
sizes[k++]=ctr;
}

void print(int a[],int s)
{for(int i=0;i<s;i++)
cout<<a[i]<<" ";
cout<<endl;
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
        store(c,ctr);
        ctr--;
        }
        else if(!unique(i))
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
    for(int i=1;i<=n;i++)
    {v=i;
    c[ctr++]=v;
  cycle(G,v);
  ctr=0;
  cout<<endl;}
  cout<<"\nAre all cycles.\n\n";
  int max=sizes[0];
  int i=0;
  while(i<k)
  {
      if(sizes[i]>max)
        {max=sizes[i];}
        i++;
  }
  for(int i=0;i<k;i++)
  {if(sizes[i]==max)
      {for(int j=0;j<sizes[i];j++)
    cout<<cycles[i][j]<<" ";}
    cout<<endl;}
  cout<<"Are cycles having the largest size.";
}
