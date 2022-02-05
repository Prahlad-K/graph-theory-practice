#include <iostream>
using namespace std;
int counter=0,n;
int G[100][100];
void paths(int current,int d)
{if(current==d)
counter++;
else
{
    for(int i=1;i<=n;i++)
    {if(G[current][i]>0)
    paths(i,d);}
}
}

int main() {
	int T,e,a,b,s,d;
cin>>T;
for(int i=1;i<=T;i++)
{counter=0;
    cin>>n>>e;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {G[i][j]=0;G[j][i]=0;}

    for(int i=1;i<=e;i++)
    {cin>>a>>b;
    G[a][b]=1;
    }
    cin>>s>>d;
    paths(s,d);
    cout<<counter<<endl;
}
	return 0;
}
