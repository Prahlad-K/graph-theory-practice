#include<iostream>
using namespace std;

// swap elements in the array
void swap(int arr[],int idx1,int idx2) {
   int temp;
   temp = arr[idx1];
   arr[idx1] = arr[idx2];
   arr[idx2] = temp;
}
int size;
// print the permutation
void printPermute(int arr[]) {
   int i;
   for (i=0;i<=size;i++) {
      cout<<arr[i]<<" ";
   }
   cout<<endl;
}
int ctr=0;
// permute the elements recursively
void permute(int arr[],int start_idx,int end_idx) {
   int i;
   if (start_idx == end_idx) {
      printPermute(arr);ctr++;
   }
   for (i=start_idx;i<=end_idx;i++) {
      swap(arr,start_idx,i);
      permute(arr,start_idx+1,end_idx);
      swap(arr,start_idx,i);
   }
}

// main
int main() {
   int arr[] = {3,2,5,4,7,6};
   size = sizeof(arr)/sizeof(arr[0]);
   size=size-1;

   cout<<"\nAll possible permutations of the given array :-\n";
   permute(arr,0,size);
   cout<<endl;
   cout<<"The total number of permutations:"<<ctr;
   return 0;
}
