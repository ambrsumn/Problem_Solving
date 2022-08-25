class Solution {
public:
    bool canConstruct(string ran, string mag) 
    {
        unordered_map<char,int> mpp;
        
        for(auto it : mag)
            mpp[it]++;
        
        for(auto it : ran)
        {
            if(mpp[it]<=0)return false;
            else mpp[it]--;
        }
        
        return true;
    }
};