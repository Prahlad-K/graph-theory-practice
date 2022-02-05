#include <iostream>

using namespace std;
    long n;
    long counter=0;
void DFT(long *G[],long current,int *visit)
{
    counter++;
    visit[current]=1;
    for(long i=1;i<=n;i++)
    {if(G[current][i]>0&&visit[i]==0)
    DFT(G,i,visit);
    }
}

void concomp(long *G[])
{
int visit[n];
long c[n];
long index=1;
for(long i=1;i<=n;i++)
visit[i]=0;

for(long i=1;i<=n;i++)
{
    if(visit[i]==0)
        {DFT(G,i,visit);
        if(counter!=1)
        c[index++]=counter;
        counter=0;}
}
long min=100000;
for(long i=1;i<index;i++)
{
if(c[i]<min)
    min=c[i];
}
long max=0;
for(long i=1;i<index;i++)
{
if(c[i]>max)
    max=c[i];
}
cout<<min<<" "<<max<<" ";
}


int main()
{
    long s;
    long a,b;
    cin>>s;
    n=2*s;
    long *G[n];
    for(long i=1;i<=n;i++)
        G[i]=new long[n];
    for(long i=1;i<=n;i++)
    {  for(long j=1;j<=n;j++)
        G[i][j]=0;}


    for(long i=1;i<=s;i++)
    {
        cin>>a>>b;
        G[a][b]=1;
        G[b][a]=1;
    }

    concomp(G);

}
