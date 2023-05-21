class FrequencyTracker {
public:
    
    map<int, int> mpp;
    map<int, int> con;
    
    FrequencyTracker() 
    {
            
    }
    
    void add(int number) 
    {
        
        if(mpp.count(number))
        {
            int prev = mpp[number];
            con[prev]--;
            
            if(con[prev] == 0)con.erase(prev);
        }
        
        mpp[number]++;
        
        con[mpp[number]]++;
    }
    
    void deleteOne(int number) 
    {
        if(mpp.count(number))
        {
            int prev = mpp[number];
            con[prev]--;
            if(con[prev] == 0)con.erase(prev);
            
            mpp[number]--;
            
            if(mpp[number] == 0)mpp.erase(number);
            
            else
            con[mpp[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) 
    {
        return con.count(frequency);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */