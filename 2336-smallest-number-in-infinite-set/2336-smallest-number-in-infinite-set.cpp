class SmallestInfiniteSet {
public:
    
    set<int> st;
    
    SmallestInfiniteSet() 
    {
        for(int i=1; i<1002; i++)
        st.insert(i);
    }
    
    int popSmallest() 
    {
        auto it = st.begin();
        int d = *it;
        st.erase(it);
        return d;
    }
    
    void addBack(int num) 
    {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */