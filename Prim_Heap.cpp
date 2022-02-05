#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
int setarray[100];
int vertex[100];
int index=1;
int sorind=1;
struct gnode
{int u,v,w;
};
gnode sorted[100];
typedef struct bnode
{
    struct bnode* lchild;
    struct gnode data;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL,leaf=NULL;
void Heap_tree(BTPTR &T,gnode H[],int s,int i)
{
    if(i<s)
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
    {if(T->data.w>T->lchild->data.w)
        return false;}
    if(T->rchild!=NULL)
    {if(T->data.w>T->rchild->data.w)
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
    {if(T->data.w>T->lchild->data.w)
        swap(T->data,T->lchild->data);}
    if(T->rchild!=NULL)
    {if(T->data.w>T->rchild->data.w)
        swap(T->data,T->rchild->data);}
    heapify(T->lchild);
    heapify(T->rchild);
    }
}
void remove_node(BTPTR R)
{
    if(R!=NULL)
    {
    if(R->lchild!=NULL&&R->lchild->data.u==leaf->data.u&&R->lchild->data.v==leaf->data.v)
    {R->lchild=NULL;return;}
    if(R->rchild!=NULL&&R->rchild->data.u==leaf->data.u&&R->rchild->data.v==leaf->data.v)
    {R->rchild=NULL;return;}
    remove_node(R->lchild);
    remove_node(R->rchild);
    }

}
BTPTR giveleaf(BTPTR T)
{
    if(T->lchild==NULL&&T->rchild==NULL)
      return T;
    else if(T->lchild!=NULL)
        return(giveleaf(T->lchild));
    else if(T->rchild!=NULL)
        return(giveleaf(T->rchild));
}
void sortheap(BTPTR T)
{
  while(T->lchild!=NULL||T->rchild!=NULL)
  {sorted[sorind++]=T->data;
  leaf=giveleaf(T);
  T->data=leaf->data;
  remove_node(root);
  heapify(T);
  }
  if(T->lchild==NULL&&T->rchild==NULL)
   sorted[sorind++]=T->data;
}

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

bool iscomplete()
{
    for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
    if(!check(i,j))
        return false;
    }
    return true;
}
int main()
{cout<<"Enter the number of vertices:";
cin>>n;
for(int i=1;i<=n;i++)
setarray[i]=0;
cout<<"Enter the number of edges:";
cin>>m;

struct gnode G[m];
for(int i=1;i<=m;i++)
{
    cin>>G[i].u>>G[i].v>>G[i].w;
}

gnode H[m+1];
BTPTR heap=NULL;
int minedge=100;
int a,b;
int counter=1;
int c=1;

gnode selected;
while(!iscomplete())
{sorind=1,c=1;
for(int i=1;i<=m;i++)
    H[i]=G[i];
T=NULL;
Heap_tree(T,H,m+1,1);
heap=root;
do
{heapify(heap);
heap=root;}while(!check_heap(heap));
sortheap(heap);
    selected=sorted[c++];
a=selected.u;
b=selected.v;

for(int i=1;i<=m;i++)
{if(G[i].u==selected.u&&G[i].v==selected.v)
    {G[i].w=1000;}}

selected.w=1000;
if(!check(a,b))
{cout<<a<<"a "<<b<<"b "<<endl;
union_nums(a,b);
if(!present(a)&&!present(b))
    {vertex[index++]=a;
    vertex[index++]=b;
    }
else if(present(a)&&!present(b))
{vertex[index++]=b;}
else if(present(b)&&!present(a))
{vertex[index++]=a;}
}
}

cout<<"Minimum spanning tree:\n";
for(int i=1;i<=n;i++)
    cout<<i<<" "<<setarray[i]<<endl;
}
