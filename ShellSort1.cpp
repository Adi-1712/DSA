#include<iostream>
using namespace std;

void ShellSort(int arr[], int n)
{
	int gap=n/2;
	while(gap>0)
	{
		for(int i=gap; i<n; i++)
		{
			int temp = arr[i];
			int j=i-gap;
			while(j>=0 && temp<arr[j])
			{
				arr[j+gap]=arr[j];
				j=j-gap;
			}
			arr[j+gap]=temp;
		}
		gap=gap/2;
	}
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	ShellSort(arr, n);
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
