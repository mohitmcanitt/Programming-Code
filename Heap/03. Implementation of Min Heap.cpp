#include <iostream>
using namespace std;

class minHeap{
    int heap_size;
    int capacity;
    int *arr;

    public:

    minHeap(int size)
    {
        heap_size=0;
        capacity=size;
        arr=new int[capacity];
    }

    bool isFULL()
    {
        if(heap_size==capacity)
            return true;
        else
            return false;   
    }

    bool isEmpty()
    {
        if(heap_size==0)
            return true;
        else
            return false;    
    }

    void Upheapify(int parent,int child) // Due to insertion of new element , heap property gets violated
    {
        while(parent>=0 and arr[parent]>arr[child])
        {
            int temp=arr[child];
            arr[child]=arr[parent];
            arr[parent]=temp;

            child=parent;
            parent=(parent-1)/2;
        }
    }

    void Downheapify(int parent)  // Due to deletion 
    {
        int smallest=parent;

        int left=2*parent+1;
        int right=2*parent+2;
        
        if(left<heap_size and arr[left]<arr[smallest])
            smallest=left;
        if(right<heap_size and arr[right]<arr[smallest])
            smallest=right;

        if(smallest!=parent)
        {
            swap(arr[smallest],arr[parent]);
            Downheapify(smallest);   
        }
                           
    }

    void insertKey(int val)
    {
        if(isFULL())
            cout<<"Heap is full\n";
        else
        {
            int child=heap_size;
            int parent=(child-1)/2;
            arr[child]=val;
            if(arr[child]<arr[parent])
                Upheapify(parent,child);
           heap_size++;
        }
    }

    void delete_root()
    {
        if(isEmpty())
            cout<<"Container is Empty"<<endl;
        else
            {
                int res=arr[0];
                swap(arr[0],arr[heap_size-1]);
                Downheapify(0);
                cout<<"Heapify : "<<res<<endl;
                heap_size--;
            }  
             
    }

    void size()
    {
        cout<<"size of heap "<<heap_size<<endl;
    }
    void  extract_min()
    {
        if(isEmpty())
            cout<<"Container is Empty"<<endl;
        else
            cout<<"Min element is "<< arr[0];    
    }

    void display()
    {
        for(int i=0;i<heap_size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
};


int main() {
    minHeap obj(6);
    obj.insertKey(15);
    obj.insertKey(5);
    obj.insertKey(10);
    obj.insertKey(3);
    obj.insertKey(4);
    obj.insertKey(12);
    obj.display();
    obj.delete_root();
    obj.display();    
}
/*
3 4 10 15 5 12 
Heapify : 3
4 5 10 15 12 
*/
