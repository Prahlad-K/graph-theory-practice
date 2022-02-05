#include <iostream>

using namespace std;
int setarray[100];
int G[100][100];
int n;

int findroot(int i)
{
    if(setarray[i]==0)
        return i;
    else
        return findroot(setarray[i]);
}

void union_nums(int a,int b)
{
    if(setarray[a]==0)
        setarray[a]=b;
    else if(setarray[b]==0)
        setarray[b]=a;
    else
        setarray[findroot(b)]=a;

}
bool check(int i,int j)
{
    if(findroot(i)==findroot(j))
        return true;
    else
        return false;
}

bool full(int *a)
{int ctr=1;
    for(int i=1;i<=n;i++)
    {if(setarray[i]!=0)
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
for(int i=1;i<=n;i++)
setarray[i]=0;

    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }
    int a,b;
    while(!full(setarray))
    {
    int minimum=G[1][2];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(G[i][j]>0)
            {
                if(G[i][j]<=minimum)
                   {minimum=G[i][j];
                   a=i;
                   b=j;
                   cout<<minimum<<" ";
                   }
            }
        }
    }
if(!check(a,b))
union_nums(a,b);
if(setarray[a]==0&&setarray[b]==0)
union_nums(a,b);
G[a][b]=-1;
    }
cout<<endl;
for(int i=1;i<=n;i++)
{
    cout<<setarray[i]<<" ";
}

}
