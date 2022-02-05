#include <iostream>
using namespace std;
int G[100][100];
int T[100][100];
int visit[100];
int n;
bool ispath(int a,int b)
{
    if(a==b)
    return true;
    else
    {
        visit[a]=1;
        for(int i=1;i<=n;i++)
        {
            if(a!=i&&G[a][i]>0&&visit[i]==0)
            {ispath(i,b);}
        }
    }
    return false;
}


int main()
{int t;
cin>>t;
for(int i=1;i<=t;i++)
{

    cin>>n;
    for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
    cin>>G[i][j];}

    for(int i=1;i<=n;i++)
    visit[i]=0;

    for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
    {if(i==j)
    T[i][j]=1;
    else
    {if(ispath(i,j))
    T[i][j]=1;}}}
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        cout<<T[i][j]<<" ";
}
	return 0;
}
