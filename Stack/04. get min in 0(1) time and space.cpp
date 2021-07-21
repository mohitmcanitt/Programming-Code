#include<iostream>
using namespace std;

class stack{
    int top=-1;
    int *arr;
    int size;
    int minEle;
    public:
    stack(int n)
    {
        size=n;
        arr=new int[size];
    }
    void push(int val)
    {
        if(isFull())
        {
            cout<<"Stack is Full"<<endl;
            return;
        }
        if(isEmpty())  // stack is empty
        {
            top=top+1;
            arr[top]=val;
            minEle=val;
        }
        else if(val>=minEle)
        {
             top=top+1;
             arr[top]=val;
        }   
        else
        {
            top=top+1;
            arr[top]=val+val-minEle;
            minEle=val;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else if(arr[top]>=minEle)
        {
            int val=arr[top];
            top=top-1;
            return val;
        }
        else
        {
            top=top-1;
            int val=minEle;
            minEle=2*minEle-val;
            return val;
        }
    }
    int topp()
    {
        if(isEmpty())
            return -1;
        else if(arr[top]>=minEle)
            return arr[top];
        else
            return minEle;                
    }
    bool isEmpty()
    {
        return top==-1?true:false;
    } 
    bool isFull()
    {
        return top==size-1?true:false;
    }   
    int getmin()
    {
       return  isEmpty()?-1:minEle;
    }
    void print()
    {
        for(int i=top;i>=0;i--)
            cout<<arr[i]<<" ";
           cout<<endl; 
    }

};

int main() {
    stack st(5);
    st.push(18);
    st.push(19);
    st.push(29);
    st.push(15);
    st.push(16); 
    st.print(); 
    cout<<"Element at the top of Stack is "<<st.topp()<<endl;
    cout<<"Minimum element is "<<st.getmin()<<endl;
}
