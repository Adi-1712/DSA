#include<iostream>
using namespace std;

void Display(int A[],int n)
{
  cout<<"\n";
  for(int i =0;i<n;i++)
      cout<<A[i]<<"\t";
  cout<<endl;
  return;     
}  
void merge(int A[],int start, int mid,int end)
{
   int i =start;
   int j= mid + 1;
   int neuA[(end-start)+1];
   int k=0;
   while(i<=mid && j<=end)
   {
     if(A[i]>A[j])
     { 
       neuA[k]=A[j];
       j++;
       k++;
     }
     else
     {
      neuA[k]=A[i];
      i++;
      k++;
     } 
  
   } for(int i=0,j=start;i<k;i++,j++)
        A[j]=neuA[i];
   return;
}  
 
 int main()
 {
   int A[]={12,34,56,76,45,23,49,78,97,65};
   int n=10;
   Display(A,n);
   merge(A,0,4,9);
   Display(A,n);
   return 0;
 }
