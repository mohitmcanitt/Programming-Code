/*The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part 
and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the end of sorted subarray.

arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4]
// and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4]
// and place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4]
// and place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4]
// and place it at beginning of arr[3...4]
11 12 22 25 64 

*/

// Iterative Code

#include <iostream>
using namespace std;

void selection_sort(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min_index]>arr[j])
                min_index=j;
        }
        if(min_index!=i)
            {
                int temp=arr[i];
                arr[i]=arr[min_index];
                arr[min_index]=temp;
            }
    }
}


// Recursive Code
/*
int minIndex(int *arr,int i,int j)
{
    if(i==j)
    return i;

    int k=minIndex(arr,i+1,j);
    
    return arr[i]<arr[k]?i:k;
}

void recurSelectionSort(int *arr,int n,int index=0)
{
    if(index==n-1)
        return;
    int min_index=minIndex(arr,index,n-1);

    if(min_index!=index)
        swap(arr[min_index],arr[index]);

   recurSelectionSort(arr,n,index+1);         
}

*/


int main() {
    int arr[]={5,4,3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

