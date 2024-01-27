// refer for approach : https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/

#include<iostream>
using namespace std;

long calculate_combination(int n, int r){
    long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return res;
}

int main(){
    int n;
    int r;
    cout<<"Enter value of n : ";
    cin>>n;
    cout<<"Enter value of r : ";
    cin>>r;
    long combination= calculate_combination(n,r);
    cout<<"Combination of given value is : "<<combination<<endl;
}