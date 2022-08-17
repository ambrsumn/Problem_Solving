class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        vector<int> rem;
        int curr=0, ans=0;
        
        for(auto it : nums)
        {
            curr += it;
            int bacha = curr%k;
            if(bacha<0)bacha += k;
            
            rem.push_back(bacha);
        }
        
        for(auto it : rem)
            cout<<it<<" ";
        
        unordered_map<int,int> mpp; mpp[0]=1;
        
        for(auto it : rem)
        {
            ans += mpp[it];
            mpp[it]++;
        }
        
        return ans;
    }
};