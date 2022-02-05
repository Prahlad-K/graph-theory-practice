#include <iostream>

using namespace std;
int n;
struct adjmat
{
    int G1[10][10];
    char data[10];
}A;

typedef struct adnode* APTR;

typedef struct gnode
{char c;
struct gnode* vnext;
struct adnode* alist;
}*GPTR;
GPTR G=NULL,start=NULL;
APTR L=NULL,head[10];

struct adnode
{
    GPTR ad;
    APTR adnext;
};
int p=0,p1=0;
void create(GPTR&,int);

GPTR search(GPTR G,int j)
{if(G!=NULL)
{
    if(G->c==A.data[j])
        return G;
    else
        return search(G->vnext,j);
}
else
    return NULL;

}


void createlist(GPTR &G)
{
int j=1;
        while(j<=n)
        {if(A.data[j]==G->c)
        break;
        j++;
        }

        for(int i=1;i<=n;i++)
        {
        if(A.G1[j][i]>0)
        {
        if(G->alist==NULL)
        {APTR N=new adnode;
        N->ad=NULL;
        N->adnext=NULL;
        N->ad=search(start,i);

        p1++;
        if(p1==1)
        head[j]=N;
        }
        else
        {while(G->alist->adnext!=NULL)
        G->alist=G->alist->adnext;
        APTR N=new adnode;
        N->ad=NULL;
        N->adnext=NULL;
        N->ad=search(start,i);

        G->alist->adnext=N;
        }
        G->alist=head[j];
        }
        }
}


void create(GPTR &G,int i)
{
    if(G==NULL)
    {
        GPTR N=new gnode;
        N->c=A.data[i];
        N->vnext=NULL;
        N->alist=NULL;
     G=N;
     if(p==0)
    {start=G;p++;}
        }
    else
    {while(G->vnext!=NULL)
    G=G->vnext;
    GPTR N=new gnode;
    N->c=A.data[i];
    N->vnext=NULL;
    N->alist=NULL;
    G->vnext=N;
    }
}


void printlist(APTR L)
{
    if(L!=NULL)
    {
        cout<<L->ad->c<<" ";
        printlist(L->adnext);
    }
}


void print(GPTR G)
{
    if(G!=NULL)
    {
        cout<<G->c<<":";
        if(G->alist!=NULL)
            printlist(G->alist);
            cout<<endl;
        print(G->vnext);
    }
}


int main()
{

cout<<"Enter number of vertices:";
cin>>n;
for(int i=1;i<=n;i++)
    head[i]=NULL;
cout<<"Enter data values of vertices:";
for(int i=1;i<=n;i++)
    cin>>A.data[i];
cout<<"Enter adjacency matrix:\n";
for(int i=1;i<=n;i++)
{for(int j=1;j<=n;j++)
{cin>>A.G1[i][j];}
}

for(int i=1;i<=n;i++)
{create(G,i);
G=start;
}
while(G!=NULL)
{createlist(G);
G=G->vnext;p1=0;}

print(start);
}
