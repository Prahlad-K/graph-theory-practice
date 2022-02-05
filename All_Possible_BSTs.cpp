#include <iostream>
#include <queue>
using namespace std;
int counter=1;
typedef struct mnode
{
    int key[50];
    struct mnode* ptr[10];
    int size;
}*MTPTR;
MTPTR T=NULL,root=NULL;
queue <MTPTR> q;
int n;
int v;
int c[100];
int ctr=0;
int courses[100];
int index=1;
int last[10];
int lastind=1;
 int G[10][10];
 int permutes[100][100];
 int perind=1;
int indegree(int i)
{int s=0;
    for(int j=1;j<=n;j++)
    {if(G[j][i]!=-1)
        s=s+G[j][i];
     else
        s=s+0;
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
            G[i][j]=-1;
    }
}

void revive_edge(int i)
{
    for(int j=1;j<=n;j++)
    {
        if(G[i][j]==-1)
            G[i][j]=1;
    }
}

int p=0;
void create(MTPTR &T)
{
    if(T==NULL)
    {
        MTPTR N=new mnode;
        int index=1;
        for(int i=1;i<=n;i++)
        {
        if(indegree(i)==0&&outdegree(i)>0)
                N->key[index++]=i;
        }
        //index is the size of the current node.
        for(int i=1;i<index;i++)
            N->ptr[i]=NULL;
        N->size=index;
        T=N;
        if(p==0)
        {
            root=T;p++;
        }
    }

    if(T!=NULL)
    {
        for(int i=1;i<T->size;i++)
        {
            remove_edge(T->key[i]);
            create(T->ptr[i]);
            revive_edge(T->key[i]);
        }

    }
}

void level_order(MTPTR T)
{
    MTPTR flag=new mnode;
    flag->key[1]=-1;
    for(int i=1;i<10;i++)
        flag->ptr[i]=NULL;
    q.push(T);
    q.push(flag);
    MTPTR T1;
    while(q.size()!=1)
    {T1=q.front();
    q.pop();
    if(T1->key[1]!=-1)
        {
            for(int i=1;i<T1->size;i++)
                cout<<T1->key[i]<<" ";
            cout<<" ";
            for(int i=1;i<T1->size;i++)
            {if(T1->ptr[i]!=NULL)
                q.push(T1->ptr[i]);
            }
        }
    else
    {cout<<endl;
        q.push(flag);
    }
    }
    q.pop();
}

void print(int *a,int n)
{

    for(int j=1;j<perind;j++)
    {
        for(int k=1;k<n;k++)
        cout<<a[k]<<" ";
        for(int i=1;i<lastind;i++)
        cout<<permutes[j][i]<<" ";
        counter++;
        cout<<endl;}

}

bool is_leaf(MTPTR T)
{
    for(int i=1;i<T->size;i++)
    {
        if(T->ptr[i]!=NULL)
            return false;
    }
    return true;
}
void printPermute(int arr[]) {
   int i;
   for (i=1;i<lastind;i++) {
      permutes[perind][i]=arr[i];
   }
   perind++;
}
void swap(int arr[],int idx1,int idx2) {
   int temp;
   temp = arr[idx1];
   arr[idx1] = arr[idx2];
   arr[idx2] = temp;
}
void permute(int arr[],int start_idx,int end_idx) {
   int i;
   if (start_idx == end_idx) {
      printPermute(arr);
   }
   for (i=start_idx;i<=end_idx;i++) {
      swap(arr,start_idx,i);
      permute(arr,start_idx+1,end_idx);
      swap(arr,start_idx,i);
   }
}
int path[100];int ind=1;
void paths(MTPTR T)
{
    if(is_leaf(T))
    {
    print(path,ind);
    }
    else
    {
        for(int i=1;i<T->size;i++)
        {path[ind++]=T->key[i];
        paths(T->ptr[i]);
        ind--;
        }
    }
}


int main()
{cout<<"Enter number of vertices:";
    cin>>n;

    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }

    for(int i=1;i<=n;i++)
    {
        if(outdegree(i)==0)
            last[lastind++]=i;
    }
    //cout<<"Topological sort is:\n";
    //toposort();
    permute(last,1,lastind-1);

    create(T);
    //T=root;
    //level_order(T);
  cout<<"All possible trees are:";
    cout<<endl;
    T=root;
    paths(T);
    cout<<"Total number of possible trees are:";
    cout<<counter-1;
}
