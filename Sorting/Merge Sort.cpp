#include<iostream>
using namespace std;

void merge(int *arr,int low,int mid,int high)
{
	int b[high-low+1];
	int k=0;
	int i=low;
	int j=mid+1;
	
	while(i<=mid and j<=high)
	{
		if(arr[i]<arr[j])
			b[k++]=arr[i++];
		else
		    b[k++]=arr[j++]	;
	}
	if(i>mid)
		{
			while(j<=high)
				b[k++]=arr[j++];
		}
	else if(j>high)
		{
			while(i<=mid)
				b[k++]=arr[i++];
		}	
	k=0;
	for(int i=low;i<=high;i++)
		arr[i]=b[k++];
		
}

void merge_sort(int *arr,int low,int high)
{
	if(low<high)
		{
			int mid=(low+high)/2;
			merge_sort(arr,low,mid);
			merge_sort(arr,mid+1,high);
			merge(arr,low,mid,high);
			
		}
}


int main()
{
	int arr[]={15,4,11,3,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
		
}
