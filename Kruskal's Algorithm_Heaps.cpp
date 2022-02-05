#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
int setarray[100];
int vertex[100];
int index=1;
int mem;
struct gnode
{int u,v,w;
};
typedef struct bnode
{
    struct bnode* lchild;
    struct gnode data;
    struct bnode* rchild;

}*BTPTR;
BTPTR T=NULL,root=NULL;
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

gnode H[10];
BTPTR heap=NULL;
int minedge;
int a,b;
int counter=0;
while(counter!=n+1)
{for(int i=1;i<=m;i++)
{
    H[i]=G[i];
}
Heap_tree(T,H,m+1,1);
heap=root;
do
{heapify(heap);
heap=root;}while(!check_heap(heap));

a=root->data.u;
b=root->data.v;
root->data.w=1000;
if(!check(a,b))
{union_nums(a,b);
if(!present(a)&&!present(b))
    counter=counter+2;
else if(present(a)||present(b))
    counter=counter+1;
}
vertex[index++]=a;
vertex[index++]=b;
}
cout<<"Minimum spanning tree:\n";
for(int i=1;i<=n;i++)
    cout<<i<<" "<<setarray[i]<<endl;
}
