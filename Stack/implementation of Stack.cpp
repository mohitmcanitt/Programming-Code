/*
removed item is 30
Items in stacks are 20 10 
Top element is 20
*/

#include<iostream>
using namespace std;

class st{
    int size;
    int *arr;
    int top=-1;
    public:
    st(int n)
    {
        size=n;
        arr=new int[size];
    }
    void insert(int val)
    {
        if(top==size)
        {
            cout<<"stack is full\n";
            return;
        }
        else
        {
            top=top+1;
            arr[top]=val;
        }
           
    }
    void remove()
    {
        if(isempty())
        {
            cout<<"Stack is underflow\n";
            return;
        }
        else
        {
            cout<<"removed item is "<<arr[top]<<endl;
            top=top-1;
        }
    }
    void top_element()
    {
        if(isempty())
        {
            cout<<"Stack is underflow\n";
            return;
        }    
        else
            cout<<"Top element is "<<arr[top]<<endl;
        
    }
    bool isempty()
    {
        if(top==-1)
            return true;
        else
            return false;    

    }
    void printelement()
    {
        if(isempty())
        {
             cout<<"Stack is empty\n";
            return;
        }
        else
        {
            cout<<"Items in stacks are ";
            for(int i=top;i>=0;i--)
                cout<<arr[i]<<" ";
                cout<<endl;
        }   
        return;
    }

};

int main() {
    st obj(5);
    obj.insert(10);
    obj.insert(20);
    obj.insert(30);
   
    obj.remove();
    obj.printelement();
    obj.top_element();
}
