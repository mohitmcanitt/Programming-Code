#include<iostream>
using namespace std;

void merge(int *arr,int low,int mid,int high)
{
    int b[high-low+1];
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid and j<=high)
    {
        if(arr[i]<arr[j])
            b[k++]=arr[i++];
        else
            b[k++]=arr[j++];    
    }
    if(i>mid) /// means all element from low to mid is processed
    {
        while(j<=high)
            b[k++]=arr[j++];
    }
    if(j>high)
    {
        while(i<=mid)
            b[k++]=arr[i++];
    }
    k=0;
    for(int i=low;i<=high;i++)
        arr[i]=b[k++];
}

void mergeSort(int *arr,int s,int e)
{
    if(s>=e)
     return;
    int mid=(s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,mid,e);
}

int main() {
    int arr[5]={5,4,1,3,2};
    int n=5;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
