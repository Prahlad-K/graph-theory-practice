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
int k=0;int w=0;int weights[10],sizes[10];
void store(int c[],int ctr,int w)
{
for(int i=0;i<ctr;i++)
{cycles[k][i]=c[i];}
sizes[k]=ctr;
weights[k++]=w;
}

void print(int a[],int s)
{for(int i=0;i<s;i++)
cout<<a[i]<<" ";
}
void cycle(int G[10][10],int a)
{
for(int i=1;i<=n;i++)
{
    if(G[a][i]>0)
    {
        if(i==v)
        {c[ctr++]=v;
        w=w+G[a][v];
        print(c,ctr);
        store(c,ctr,w);
        cout<<endl;
        ctr--;
        w=w-G[a][v];
        }
        else if(!unique(i))
        {c[ctr++]=i;
        w=w+G[a][i];
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
  ctr=0;w=0;
  cout<<endl;}
  int max=weights[1];
  int i=0;
  while(i<k)
  {
      if(weights[i]>max)
        {max=weights[i];}
        i++;
  }
  int index;
  for(int i=0;i<k;i++)
  {
      if(max==weights[i])
        {index=i;break;}
}

  for(int j=0;j<sizes[index];j++)
    cout<<cycles[index][j]<<" ";
  cout<<" is a cycle having maximum weight: "<<max;

}
