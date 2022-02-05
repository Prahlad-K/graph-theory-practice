#include <iostream>
#include <stack>
#include <queue>
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

typedef struct bnode
{
    struct bnode* lchild;
    int data;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;
queue <BTPTR> q;

BTPTR flag,T1;
void level_order(BTPTR T)
{flag=new bnode;
flag->data='-';flag->lchild=NULL;flag->rchild=NULL;
    q.push(T);q.push(flag);
   while(q.size()!=1)
   {T1=q.front();
   q.pop();
   if(T1->data!='-')
   {cout<<T1->data<<" ";
   if(T1->lchild!=NULL)
     q.push(T1->lchild);
   if(T1->rchild!=NULL)
    q.push(T1->rchild);}
   else
   {q.push(T1);cout<<"\n";}
   }
   q.pop();
}


void Heap_tree(BTPTR &T,int H[],int s,int i)
{
    if(i<s&&H[i]!='-')
    {if(T==NULL)
    {BTPTR N;
    N=new bnode;
    N->data=H[i];
    N->lchild=NULL;
    N->rchild=NULL;
    T=N;
    if(i==1)
    root=T;
    }
    Heap_tree(T->lchild,H,s,2*i);
    Heap_tree(T->rchild,H,s,2*i+1);}
}

bool check_heap(BTPTR T)
{
    if(T!=NULL)
    {if(T->lchild!=NULL)
    {if(T->data>T->lchild->data)
        return false;}
    if(T->rchild!=NULL)
    {if(T->data>T->rchild->data)
        return false;}
    return(check_heap(T->lchild)&&check_heap(T->rchild));
    }
    else
    return true;
}

void heapify(BTPTR T)
{
    if(T!=NULL)
    {if(T->lchild!=NULL)
    {if(T->data>T->lchild->data)
        swap(T->data,T->lchild->data);}
    if(T->rchild!=NULL)
    {if(T->data>T->rchild->data)
        swap(T->data,T->rchild->data);}
    heapify(T->lchild);
    heapify(T->rchild);
    }
}
BTPTR heap=NULL;

int retmin(vertex *V)
{

    int *H;
    H=new int;
    int j=1;
   for(int i=1;i<=n;i++)
    {if(V[i].visit==0)
    H[j++]=V[i].dis;}

    Heap_tree(T,H,j,1);
    T=root;

    do
    {   heapify(heap);
        heap=root;
    }while(!check_heap(heap));
    int ret=heap->data;
    for(int i=1;i<=n;i++)
    {if(V[i].dis==ret&&V[i].visit!=1)
        return i;
    }
}

int main()
{
    cout<<"Enter number of vertices:";
    cin>>n;
     struct vertex V[10];
     int index;
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
    int c;
    c=s;
    while(c!=d)
    {
        for(int i=1;i<=n;i++)
        {if(G[c][i]>0)
        {
        if(V[i].visit==0)
        {
            if(c==s)
            {V[i].dis=G[c][i];
                V[i].via=c;}
        else if(V[i].dis>(V[c].dis+G[c][i]))
        {V[i].dis=V[c].dis+G[c][i];
        V[i].via=c;}
        }}
        }
 V[c].visit=1;
 index=retmin(V);
 heap=NULL;root=NULL;T=NULL;
 c=index;
}
cout<<"Shortest path:\n";
while(c!=s)
{S.push(c);
c=V[c].via;
}
S.push(s);
while(S.size()!=0)
{cout<<S.top()<<" ";
S.pop();
}
}



