class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) 
    {
        vector<int> pre, suff;
        
        map<int, int> mpp;
        
        for(auto it : nums)
        {
            mpp[it]++;
            pre.push_back(mpp.size());
        }
        
        mpp.clear();
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            suff.push_back(mpp.size());
            mpp[nums[i]]++;
        }
        
        reverse(suff.begin(), suff.end());
        
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++)
        {
            ans.push_back(pre[i]-suff[i]);
        }
        
        return ans;
    }
};