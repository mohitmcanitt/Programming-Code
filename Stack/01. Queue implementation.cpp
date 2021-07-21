/*
Items in queues are 10 20 30 
removed item is 10
removed item is 20
removed item is 30
queue is empty
Items in queues are 10 20 30 40 50 
Top element is 10

*/

#include<iostream>
using namespace std;

class qu{
    int size;
    int *arr;
    int front;
    int rear;

    public:
    qu(int n)
    {
        size=n;
        arr=new int[size];
        front=-1;
        rear=-1;
    }
    void push(int val)
    {
        if(rear==size-1)
        {
            cout<<"queue is full\n";
            return;
        }
        else
        {
            if(front==-1)
                front=0;

            rear=rear+1; 
            arr[rear]=val; 
              
        }
           
    }
    void pop()
    {
        if(isempty())
        {
            cout<<"queue is underflow\n";
            return;
        }
        else
        {
            cout<<"removed item is "<<arr[front]<<endl;
            front=front+1;
            if(front>rear)
                front=rear=-1;
        }
    }
    void top_element()
    {
        if(isempty())
        {
            cout<<"queue is underflow\n";
            return;
        }    
        else
            cout<<"Top element is "<<arr[front]<<endl;
        
    }
    bool isempty()
    {
        if(front==-1 or front>rear)
            return true;
        else
            return false;    

    }
    void printelement()
    {
        if(isempty())
        {
             cout<<"queue is empty\n";
            return;
        }
        else
        {
            cout<<"Items in queues are ";
            for(int i=front;i<=rear;i++)
                cout<<arr[i]<<" ";
                cout<<endl;
        }   
        return;
    }

};

int main() {
    qu obj(5);
    obj.push(10);
    obj.push(20);
    obj.push(30);

    obj.printelement();

    obj.pop();
    obj.pop();
    obj.pop();

    obj.printelement();

    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(40);
    obj.push(50);

    obj.printelement();
    obj.top_element();
}
