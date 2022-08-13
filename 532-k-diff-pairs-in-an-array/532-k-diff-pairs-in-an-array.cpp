class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        map<int,int> mpp;
        
        for(auto it : nums)
            mpp[it]++;
        
        int ans=0;
        for(auto it : mpp)
        {
            int d = it.first-k;
            
            if(d != it.first && mpp[d]>0)
            ans++;
            
            else if(d == it.first && mpp[d]>1)
                ans++;
        }
        
        return ans;
    }
};