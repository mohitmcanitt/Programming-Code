class MyCircularQueue {
public:
    int size;
    int *que;
    int front=-1;
    int rear=-1;
    MyCircularQueue(int k) {
        size=k;
        que=new int[size];
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(front==-1 and rear==-1)
            front=0;
        rear=(rear+1)%size;
        que[rear]=value;     
        
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        front=(front+1)%size;
        return true;
        
    }
    int Front() {
          if(isEmpty())
              return -1;
        else
            return que[front];
    }
    
    int Rear() {
         if(isEmpty())
              return -1;
        else
            return que[rear];
    }
    
    bool isEmpty() {
       if(front==-1 and rear==-1)
           return true;
        else
            return false;
    }
    
    bool isFull() {
        
        if((rear+1)%size==front)
            return true;
        else
            return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
