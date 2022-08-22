class MyCircularDeque {
public:
    deque<int> dq;
    int size=0,max=0;
    
    MyCircularDeque(int k) {
        max=k;
    }
    
    bool insertFront(int value) 
    {
        if(size<max)
        {
            dq.push_front(value);
            size++;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) 
    {
        if(size<max)
        {
            dq.push_back(value);
            size++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() 
    {
        if(size==0)return false;
        
        dq.pop_front();
        size--;
        return true;
    }
    
    bool deleteLast() 
    {
        if(size==0)return false;
        
        dq.pop_back();
        size--;
        return true;    
    }
    
    int getFront() 
    {
        if(size==0)return -1;
        
        return dq.front();
    }
    
    int getRear() 
    {
        if(size==0)return -1;
        
        return dq.back();
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
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */