#include <iostream>
using namespace std;

int partition(int *arr,int low,int high)
{
    int pivot=arr[low]; // taking first element as pivot

    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot && i<j)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j)
         swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
	
}

void quickSort(int *arr,int low,int high)
{
    if(low<high)
    {
        int pivot=partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}

int main() {
    int arr[]={4,6,2,5,7,9,1,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
