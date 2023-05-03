class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        map<int, int> mpp1, mpp2;
        
        for(auto it : nums1)mpp1[it]++;
        for(auto it : nums2)mpp2[it]++;
        
        vector<vector<int>> ans(2);
        
        for(auto it : mpp1)
        {
            if(mpp2.count(it.first) == 0)ans[0].push_back(it.first);
        }
        
        for(auto it : mpp2)
        {
            if(mpp1.count(it.first) == 0)ans[1].push_back(it.first);
        }
        
        return ans;
    }
};