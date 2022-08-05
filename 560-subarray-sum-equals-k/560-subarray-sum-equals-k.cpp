class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int ans=0;
        map<int,int> mpp;
        mpp[0]=1;
        
        int curr=0;
        for(auto it : nums)
        {
            curr += it;
            int diff = curr-k;
            
            if(mpp.count(diff))
                ans += mpp[diff];
            
            mpp[curr]++;
        }
        
        return ans;
    }
};