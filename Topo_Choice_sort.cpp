#include <iostream>
using namespace std;

    int n;
    int v;
int c[100];
int ctr=0;
int courses[100];
int index=1;
int size;
int last;
 int G[10][10];
int indegree(int i)
{int s=0;
    for(int j=1;j<=n;j++)
    {
        s=s+G[j][i];
    }
    return s;
}

int outdegree(int i)
{int s=0;
    for(int j=1;j<=n;j++)
    {
        s=s+G[i][j];
    }
    return s;
}

void remove_edge(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(G[i][j]>0)
            G[i][j]=0;
    }
}

int chosen;
void toposort()
{
    if(size!=1)
    {for(int i=1;i<=n;i++)
    {  if(indegree(i)==0&&outdegree(i)>0)
        {courses[index++]=i;}}
    for(int i=1;i<=n;i++)
        {if(courses[i]!=0)
        cout<<courses[i]<<" ";}
    cout<<" are available courses.\n";

    cout<<"Enter the course you want to choose:";
    cin>>chosen;
   remove_edge(chosen);
   size--;
   index=1;
   for(int i=1;i<=n;i++)
   courses[i]=0;
   toposort();}
   else
   {cout<<last<<" is the only course left to choose.";}
}

int main()
{cout<<"Enter number of vertices:";
    cin>>n;
size=n;
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }

    for(int i=1;i<=n;i++)
    {
        if(outdegree(i)==0)
            last=i;
    }
    toposort();
}
