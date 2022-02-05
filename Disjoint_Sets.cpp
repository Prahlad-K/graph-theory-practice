#include <iostream>
using namespace std;

int setarray[10];

bool atleast1()
{
    for(int i=0;i<10;i++)
    {if(i!=0&&setarray[i]==0)
        return true;
    }
    return false;
}


int findroot(int i)
{
    if(atleast1())
    {if(setarray[i]==0)
        return i;
    else
        return findroot(setarray[i]);}
        else
            return -1;
}

void union_nums(int a,int b)
{
    if(setarray[a]==0)
        setarray[a]=b;
    else if(setarray[b]==0)
        setarray[b]=a;
    else
        setarray[findroot(b)]=a;

}

void check(int i,int j)
{
    if(findroot(i)==findroot(j))
        cout<<"They're from the same set.\n";
    else
        cout<<"They're from different sets.\n";
}

int main()
{for(int i=1;i<10;i++)
setarray[i]=0;
char ch;int a,b;
cout<<"Union?:";
cin>>ch;
while(ch!='n')
{cout<<"Enter the 2 numbers to be unioned:";
cin>>a>>b;
union_nums(a,b);
cout<<"Union?:";
cin>>ch;
}
int i,j;
cout<<"Check for two numbers?:";
cin>>ch;
while(ch!='n')
{cout<<"Enter the two numbers:\n";
cin>>i>>j;
 check(i,j);
 cout<<"Check for two numbers?:";
cin>>ch;
}
}
