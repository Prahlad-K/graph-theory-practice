#include <iostream>
using namespace std;
int n,start;
int euler[100];
int splice[100];
int index=1;
int ind=1;
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

int degree(int i)
{int s=0;
    for(int j=1;j<=n;j++)
    {
        s=s+G[j][i];
    }
    return s;
}

bool iscomplete()
{int ctr=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(G[i][j]==0)
                ctr++;
        }
    }
    if(ctr==n*n+1)
        return true;
    else
        return false;
}


bool DFT(int current,int *a)
{
  if(current==start&&index!=prevind)
    {
    if(iscomplete())
    return true;
    else
    return false;
    }

    a[index++]=current;
    //cout<<current<<endl;
    for(int i=1;i<=n;i++)
    {if(G[current][i]>0)
    {G[current][i]=0;
    G[i][current]=0;
    return(DFT(i,a));
    }
    }
}

bool eulerian()
{int ctr=1;
    for(int i=1;i<=n;i++)
    {
        if(degree(i)%2==0)
            ctr++;
    }
    if(ctr==n+1)
        return true;
    else
        return false;
}


int main()
{

    cout<<"Enter number of vertices:";
    cin>>n;

    int visit[n+1];
    for(int i=1;i<=n;i++)
        visit[i]=0;

    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }

    if(!eulerian())
    {cout<<"The given graph isn't eulerian.";return 0;}

    int firststart;
    cout<<"Enter the starting vertex:";
    cin>>start;
    firststart=start;
   int size;
   int increment=0;
   bool res=DFT(start,euler);//only one part of euler cycle turns up.
   size=index;//stores the actual size of the found euler cycle.
   euler[index++]=start;
       int nextstart;
   int pos;
   while(!res)//incomplete euler cycle.
   {
       for(int i=1;i<=n;i++)
       {
           if(degree(euler[i])>0)
           {nextstart=euler[i];break;}
       }

       start=nextstart;//the next start must give it's location to start.
       for(int i=1;i<=n;i++)
       {
        if(euler[i]==nextstart)
           {pos=i;break;}
       }
       index=pos;
       prevind=index;
       res=DFT(start,splice);
       increment=index-prevind;
       for(int i=size-1;i>pos;i--)
       {euler[i+increment]=euler[i];}
       for(int i=pos;i<pos+increment;i++)
       euler[i]=splice[i];

       size=size+increment;
      euler[index++]=start;
   }

   euler[size++]=firststart;

   cout<<"Euler cycle is:";
   for(int i=1;i<size;i++)
        cout<<euler[i]<<" ";
        cout<<endl;
}
