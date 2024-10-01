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

void arr(int A[],int start,int end)
{
  int temp =start;
  int i =start+1;
  int j =end;
  while(i<=j)
  {
    if(temp<A[i])
    { i++;
    else
    { 
    }
    if(temp<A[j])
    { j++;
    }
  }
    
      
