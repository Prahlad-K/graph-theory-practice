#include <iostream>
#include <queue>
using namespace std;
int n,start;
queue <int> q;
int level[10][10];
int l=1;int inx=1;int sizes[10];
void BFT(int G[10][10],int current,int *visit)
{
    q.push(current);
    visit[current]=1;
    int flag=-1;
    q.push(flag);
    while(q.size()!=1)
    {
        current=q.front();
        q.pop();
        if(current!=-1)
        {level[l][inx++]=current;
        cout<<current<<" ";
        for(int i=1;i<=n;i++)
        {
            if(G[current][i]>0&&visit[i]==0)
                {visit[i]=1;q.push(i);}
        }
        }
        else
        {
            sizes[l++]=inx;
            inx=1;
            q.push(current);
        }
    }
    sizes[l]=inx;
    q.pop();
}
void BFT2(int G[10][10],int current,int *visit)
{
    q.push(current);
    visit[current]=1;
    int flag=-1;
    q.push(flag);
    while(q.size()!=1)
    {
        current=q.front();
        q.pop();
        if(current!=-1)
        {level[l][inx++]=current;
        cout<<current<<" ";
        for(int i=n;i>=1;i--)
        {
            if(G[current][i]>0&&visit[i]==0)
                {visit[i]=1;q.push(i);}
        }
        }
        else
        {
            sizes[l++]=inx;
            inx=1;
            q.push(current);
        }
    }
    sizes[l]=inx;
    q.pop();
}


void swap(int arr[],int idx1,int idx2) {
   int temp;
   temp = arr[idx1];
   arr[idx1] = arr[idx2];
   arr[idx2] = temp;
}
void print(int *a,int index)
{
for(int j=1;j<sizes[index];j++)
{
    level[index][j]=a[j];
}
for(int i=1;i<=l;i++)
{
    for(int j=1;j<sizes[i];j++)
    {
        cout<<level[i][j]<<" ";
    }
}
}

void permute(int arr[],int start_idx,int end_idx,int index) {
   int i;
   if (start_idx == end_idx) {
      {print(arr,index);
      cout<<endl;}
   }
   for (i=start_idx;i<=end_idx;i++) {
      swap(arr,start_idx,i);
      permute(arr,start_idx+1,end_idx,index);
      swap(arr,start_idx,i);
   }
}

void allpossible()
{
    int arr[100];
    for(int i=1;i<=l;i++)
    {
        for(int j=1;j<sizes[i];j++)
        {
            arr[j]=level[i][j];
        }
    permute(arr,1,sizes[i]-1,i);
    cout<<endl;
}
}


int main()
{

    cout<<"Enter number of vertices:";
    cin>>n;
    int G[10][10];
    int visit[n+1];
    for(int i=1;i<=n;i++)
        visit[i]=0;
    for(int i=1;i<=n;i++)
    { for(int j=1;j<=n;j++)
        {cin>>G[i][j];}
    }

    cout<<"Enter the starting vertex:";
    cin>>start;


    BFT(G,start,visit);
    cout<<endl;
    for(int i=1;i<=n;i++)
        visit[i]=0;
    BFT2(G,start,visit);


}
