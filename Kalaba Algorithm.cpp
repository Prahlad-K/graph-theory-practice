#include <iostream>
#include <algorithm>
using namespace std;
int n;
int G[100][100];
int Gtemp[100][100];
int Gmain[100][100];
int setarray[100];
int vertex[100];
int index=1;
int cyind=1;
int c[100];
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

}
bool unique(int num)
{
    for(int i=1;i<cyind;i++)
    {if(c[i]==num)
        return false;
    }
        return true;

}
void deunion(int a,int b)
{
    for(int i=1;i<=n;i++)
    {
        if(i==a&&setarray[i]==b)
            {setarray[i]=0;return;}
        if(i==b&&setarray[i]==a)
            {setarray[i]=0;return;}
    }
}

void generateG(int i,int j)
{
    for(int i=1;i<=n;i++)
    {
        Gtemp[i][setarray[i]]=Gmain[i][setarray[i]];
        Gtemp[setarray[i]][i]=Gmain[setarray[i]][i];
    }
    Gtemp[i][j]=Gmain[i][j];
    Gtemp[j][i]=Gmain[j][i];
    for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
    {cout<<Gtemp[i][j]<<" ";}
    cout<<endl;}
}


bool storecycle(int a,int v)
{
for(int i=1;i<=n;i++)
{
    if(Gmain[a][i]>0)
    {
        if(i==v)
        {c[cyind++]=v;
        return true;
        }
        else if(unique(i))
        {c[cyind++]=i;
        storecycle(i,v);
        }
    }
    if(a!=v&&i==n)
    cyind--;
}
}

bool check(int i,int j)
{
    if(findroot(i)==findroot(j))
        return true;
    else
        return false;
}
bool present(int x)
{
    for(int i=1;i<index;i++)
    {
        if(vertex[i]==x)
            return true;
    }
    return false;
}
int main()
{cout<<"Enter the number of vertices:";
cin>>n;
for(int i=1;i<=n;i++)
setarray[i]=0;

for(int i=1;i<=n;i++)
 for(int j=1;j<=n;j++)
        cin>>G[i][j];

for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
Gmain[i][j]=G[i][j];
}

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
        Gtemp[i][j]=0;
}

int minedge=100;
int a,b;
int counter=0;
int r;
vertex[index++]=1;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        if(G[i][j]>0)
        {
            if(check(i,j))
            {cout<<i<<"i "<<j<<"j"<<endl;
            generateG(i,j);
            storecycle(i,i);
            for(int i=1;i<cyind;i++)
                cout<<c[i]<<" ";
            cout<<endl;
            int max=0;
            for(int i=1;i<cyind-1;i++)
            {
                if(G[c[i]][c[i+1]]>max)
                {
                    max=G[c[i]][c[i+1]];
                    a=i;
                    b=i+1;
                }
            }
            cyind=1;
           if(!((a==i&&b==j)||(a==j&&b==i)))
            {
                deunion(a,b);
                union_nums(i,j);
            }
            }
            else
                {union_nums(i,j);
                a=i;b=j;}

            G[a][b]=0;
            G[b][a]=0;
        }
    }
}

cout<<"Minimum spanning tree:\n";
for(int i=1;i<=n;i++)
    cout<<i<<" "<<setarray[i]<<endl;
}
