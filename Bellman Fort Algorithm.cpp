#include <iostream>
#include <stack>
using namespace std;

    int n;
    int v;
int c[100];
int ctr=0;

struct vertex
{int dis=100;
int via=0;
int visit=0;
};
stack <int> S;

bool allvisited(vertex *V)
{
    for(int i=1;i<=n;i++)
    {
        if(V[i].visit==0)
            return false;
    }
    return true;
}



int main()
{
    cout<<"Enter number of vertices:";
    cin>>n;
     struct vertex V[10];
     int G[10][10];
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }
    int s,d;
    cout<<"Enter the source vertex:";
    cin>>s;
    cout<<"Enter destination vertex:";
    cin>>d;
V[s].dis=0;
   for(int c=1;c<=n;c++)
    {for(int i=1;i<=n;i++)
        {if(G[c][i]!=0)
        {if(V[i].dis>(V[c].dis+G[c][i]))
        {V[i].dis=V[c].dis+G[c][i];
        V[i].via=c;}
        }
        }
    }

if(V[d].dis==100)
{cout<<"Impossible path!\n";return 0;}

cout<<"Shortest path:\n";
cout<<"Cost is "<<V[d].dis<<endl;
while(d!=s)
{S.push(d);

d=V[d].via;
}
S.push(s);
while(S.size()!=0)
{cout<<S.top()<<" ";
S.pop();
}
cout<<"Checking for negative cycles:\n";
for(int c=1;c<=n;c++)
{for(int i=1;i<=n;i++)
{
    if(G[c][i]!=0)
    {
        if(V[i].dis>V[c].dis+G[c][i])
        {cout<<"Negative cycle at "<<c<<":";return 0;}
    }
}

}


}



