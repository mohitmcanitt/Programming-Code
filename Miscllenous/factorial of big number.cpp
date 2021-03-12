/* 
Calculate factorial of a large number

1!=1
2!=2
3!=6
'''
'''
30!=265252859812191058636308480000000
We can store such large value in any datatype.

Approach:
Will store ans is interger array..

Ex: let suppose
calculate 5!

1*2*3*4*5

for 1 -->  1
for 2 -->  2
for 3 -->  6
for 4 -->  42
for 5 -->  021

steps:
0. Intialize int arr[100];
1. arr[0]=1
2. will maintain how many elements are in array
3. for a particular number
    6
    now for 4
    6*4=24
    array store 4 2
    now for 5
    5*4=20
    array 0,2 with carry 2
    2 *5 + carray(2)=12
    array 0 2 1
input
30
output
265252859812191058636308480000000
*/


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[1000];
    arr[0]=1;
    int n;
    cin>>n;
    int no_of_digits=1;
    for(int i=1;i<=n;i++)
    {
        int start=0,carry=0; // will iterate from 0th index to no_of_digits
        while(start<no_of_digits)
        {
            int curr_num=arr[start]*i+carry;
            carry=curr_num/10;
            arr[start]=curr_num%10;
            start++;
        }
        while(carry>0)
        {
            arr[no_of_digits]=carry%10;
            carry/=10;
            no_of_digits++;
        }
    }
    for(int i=no_of_digits-1;i>=0;i--)
    cout<<arr[i];
}
