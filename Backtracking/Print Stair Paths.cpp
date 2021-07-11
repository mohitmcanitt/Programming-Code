// https://www.pepcoding.com/resources/online-java-foundation/recursion-on-the-way-up/print-stair-paths-official/ojquestion




void printStairPaths(int n, string psf){
    // write your code here
    if(n<0)
    return;
    if(n==0)
    {
        cout<<psf<<endl;
        return;
    }
    printStairPaths(n-1,psf+'1');
    printStairPaths(n-2,psf+'2');
    printStairPaths(n-3,psf+'3');
    
    
}

int main(){

    int n;
    cin >> n;
    printStairPaths(n, "");
}
