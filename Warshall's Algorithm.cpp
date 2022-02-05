#include <iostream>
using namespace std;
int G[100][100];int n;
int R[100][100];
int main()
{
    cout<<"Enter the number of vertices:";
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {cin>>G[i][j];
        R[i][j]=G[i][j];}

for(int k=1;k<=n;k++)
   {for(int i=1;i<=n;i++)
    {for(int j=1;j<=n;j++)
    {
     if(R[i][j]<R[i][k]+R[k][j])
        R[i][j]=R[i][k]+R[k][j];

    }
    }
   }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<R[i][j]<<" ";
        cout<<endl;
    }
}
