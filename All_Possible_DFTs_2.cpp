#include <iostream>
#include <queue>
using namespace std;
int G[10][10];
typedef struct bnode
{
    int key;
    struct bnode* ptr[20];
    int deg=1;
    int neighbours[10];
}*BTPTR;
BTPTR T=NULL,root=NULL;
queue <BTPTR> q;
int n,start;
int index=1;

void print(int *a,int s)
{
    for(int i=1;i<s;i++)
        cout<<a[i]<<" ";
        cout<<endl;
}
int p=0;

void create(BTPTR &T,int current,int *visit)
{
    if(T==NULL)
    {
        BTPTR N=new bnode;
        N->key=current;
        visit[current]=1;

       for(int i=1;i<=n;i++)
       {
           if(G[current][i]>0&&visit[i]==0)
            {N->neighbours[N->deg++]=i;}
       }
        for(int i=1;i<N->deg;i++)
            N->ptr[i]=NULL;
        T=N;
        if(p==0)
        {root=T;p++;}
    }
    if(T!=NULL)
    {
        for(int i=1;i<T->deg;i++)
        {create(T->ptr[i],T->neighbours[i],visit);
        visit[T->neighbours[i]]=0;
        }
    }
}

bool is_leaf(BTPTR T)
{
    for(int i=1;i<T->deg;i++)
    {
        if(T->ptr[i]!=NULL)
            return false;
    }
    return true;
}
int path[100];int ind=1;
void paths(BTPTR T)
{
    path[ind++]=T->key;

    if(is_leaf(T))
    {print(path,ind);}
    else
    {
        for(int i=1;i<T->deg;i++)
        {paths(T->ptr[i]);
        }
    }
    ind--;
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

    cout<<"Enter the starting vertex:";
    cin>>start;
    int current=start;
    create(T,current,visit);
    T=root;
    paths(T);
}
