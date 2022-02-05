#include <iostream>
using namespace std;
int n,start;
int euler[100];
int splice[100];
int index=1;
int ind=1;
int G[100][100];
int mainG[100][100];
int prevind=1;
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

void cycle(int a)
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
        cycle(i);
        }
    }
    if(a!=v&&i==n)
    ctr--;
    else if(a==v&&i==n)
    return;
}
}

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
        if(degree(i)%2!=0)
            return false;
    }
        return true;
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
        {cin>>mainG[i][j];}
    }
    for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           G[i][j]=mainG[i][j];
       }
   }

    if(!eulerian())
    {cout<<"The given graph isn't eulerian.";return 0;}

    cout<<"Enter starting vertex:";
    cin>>v;
    c[ctr++]=v;
    cycle(v);
    for(int i=1;i<cycleno;i++)
  {
      for(int j=1;j<cyclesizes[i];j++)
        cout<<cycles[i][j]<<" ";
      cout<<endl;
  }

  int firststart;int size;int increment;bool res;int nextstart;
   int pos;
    for(int i=1;i<cycleno;i++)
    {
        for(int j=1;j<cyclesizes[i];i++)
        {
            euler[i]=cycles[i][j];
        }

        for(int j=1;j<cyclesizes[i];i++)
        {
            cout<<euler[i]<<" ";
        }
    start=euler[1];
    firststart=start;
   for(int i=1;i<cyclesizes[i]-1;i++)
   {G[i][i+1]=0;}

   increment=0;
   res=iscomplete();//only one part of euler cycle turns up.
   index=cyclesizes[i]++;//stores the actual size of the found euler cycle.
      /*for(int i=1;i<size;i++)
        cout<<euler[i]<<" ";
        cout<<endl;*/

   while(!res)//incomplete euler cycle.
   {
       for(int i=1;i<=n;i++)
       {
           if(degree(euler[i])>0)
           {nextstart=euler[i];break;}
       }
       //cout<<nextstart<<" is the nextstart.\n";
       start=nextstart;//the next start must give it's location to start.
       for(int i=1;i<=n;i++)
       {
        if(euler[i]==nextstart)
           {pos=i;break;}
       }
       //cout<<pos<<" is pos.\n";
       index=pos;
       prevind=index;
       res=DFT(start,splice);

       /*cout<<"This is splice!\n";
       for(int i=prevind;i<index;i++)
        cout<<splice[i]<<" ";
       cout<<endl;*/
       increment=index-prevind;
       //shifting, must be done based on next partition size.

       //cout<<size<<" is previous size\n";

       for(int i=size-1;i>pos;i--)
       {euler[i+increment]=euler[i];}
       for(int i=pos;i<pos+increment;i++)
       euler[i]=splice[i];

       size=size+increment;
       //cout<<size<<" is size\n";
      euler[index++]=start;
      /*for(int i=1;i<size;i++)
        cout<<euler[i]<<" ";
        cout<<endl;*/
   }

   euler[size++]=firststart;

   cout<<"Euler cycle is:";
   for(int i=1;i<size;i++)
        cout<<euler[i]<<" ";
        cout<<endl;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           G[i][j]=mainG[i][j];
       }
   }

    }

}
