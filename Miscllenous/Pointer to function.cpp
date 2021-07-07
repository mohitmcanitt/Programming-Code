#include<iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int (*fp)(int,int);
	fp=max;
	cout<<(*fp)(10,5);
	fp=min;
	cout<<endl;
	cout<<(*fp)(10,5);
}
