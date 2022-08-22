class MyCircularQueue {
public:
    deque<int> dq;
    int size=0,max=0;
    
    MyCircularQueue(int k) 
    {
        max=k;
    }
    
    bool enQueue(int value) 
    {
        if(size<max)
        {
            dq.push_front(value);
            size++;
            return true;
        }
        return false;    
    }
    
    bool deQueue() 
    {
        if(size==0)return false;
        
        dq.pop_back();
        size--;
        return true;    
    }
    
    int Front() 
    {
        if(size==0)return -1;
        
        return dq.back();
    }
    
    int Rear() 
    {
        if(size==0)return -1;
        
        return dq.front();
    }
    
    bool isEmpty() 
    {
        return dq.empty();
    }
    
    bool isFull() 
    {
        if(size==max)return true;
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