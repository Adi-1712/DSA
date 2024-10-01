#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	for(int gap=n/2; gap>0; gap=gap/2)
	{
		for(int j=gap; j<n; j++)
		{
			for(int i=j-gap; i>=0; i-=gap)
			{
				if(arr[i+gap]>arr[i])
				{
					break;
				}
				else{
					int temp = arr[i+gap];
					arr[i+gap] = arr[i];
					arr[i] = temp;
				}
			}
		}
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}

