/*
Insertion sort works similar to the way you sort playing cards in your hands.
The array is virtually split into a sorted and an unsorted part. 
Values from the unsorted part are picked and placed at the correct position in the sorted part.

Algorithm 
To sort an array of size n in ascending order: 
1: Iterate from arr[1] to arr[n] over the array. 
2: Compare the current element (key) to its predecessor. 
3: If the key element is smaller than its predecessor, compare it to the elements before. Move the greater elements one position up to make space for the swapped element.

*/

#include <iostream>
using namespace std;

void insertion_sort(int *arr,int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i]<arr[i-1])
        {
            int num=arr[i];
            int j=i-1;
            while(j>=0 and arr[j]>num)
            {
                arr[j+1]=arr[j];
                j--;
            }  
            arr[j+1]=num;  
        }
    }
}
/* Recursive code
void recur_insertion_sort(int *arr,int n,int index=1)
{
    if(index==n)
    return;

    if(arr[index]<arr[index-1])
        {
            int num=arr[index];
            int j=index-1;
            while(j>=0 and arr[j]>num)
                {
                    arr[j+1]=arr[j];
                    j--;
                }
                arr[j+1]=num;
        }

    recur_insertion_sort(arr,n,index+1);
}
*/

int main() {
    int arr[]={5,4,3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
