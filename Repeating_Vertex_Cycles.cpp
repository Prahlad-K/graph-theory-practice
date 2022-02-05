#include <iostream>
using namespace std;

    int n;
    int v;
int c[100];
int ctr=0;
int cycles[10][10];
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
        cout<<endl;
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

  int freq[n+1];int count=0;
  int c;
  //stores frequency of all occurrences of elements
  for(int i=1;i<=n;i++)
  {c=i;
  for(int x=0;x<k;x++)
  {
      for(int y=0;y<k;y++)
      {
       if(c==cycles[x][y])
        count++;
       }
  }
  freq[i]=count;count=0;
  }
  for(int i=1;i<=n;i++)
    cout<<freq[i]<<" ";
  cout<<endl;
int max=freq[1];
for(int i=1;i<=n;i++)
{
if(freq[i]>=max)
{max=freq[i];}
}
for(int i=1;i<=n;i++)
{if(freq[i]==max)
cout<<i<<" ";
}
cout<<"occur the most in all cycles.";
}
