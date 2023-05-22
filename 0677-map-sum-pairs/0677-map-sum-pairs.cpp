class MapSum {
public:
    
    map<string, int> mpp;
    MapSum() 
    {
        mpp.clear();    
    }
    
    void insert(string key, int val) 
    {
        mpp[key] = val;    
    }
    
    int sum(string prefix) 
    {
        int ans = 0;
        
        for(auto it : mpp)
        {
            string temp = it.first;
            if(temp.length() < prefix.length())continue;
            
            int i=0;
            int flag=0;
            
            while(i<prefix.length())
            {
                if(temp[i] != prefix[i])
                {
                    flag=1;
                    break;
                }
                
                i++;
            }
            
            if(!flag)ans += it.second;
        }
        
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */