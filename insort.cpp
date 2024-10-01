#include<iostream>
using namespace std;
int main()
{
 int n,i,j,temp;
 int arr[100];
 cout<<"Enter No of elements to be added to the array :";
 cin>>n;
 for(i=1;i<n;i++)
 {
   temp=arr[i];
   while(j>=0 && arr[j]>temp)
   {
     arr[j+1]=arr[j];
     j--;
   }
   arr[j+1]=temp;
 }
 for(i=1;i<n;i++)
  {
   cout<<arr[i];
  } 
  return 0;
 }
