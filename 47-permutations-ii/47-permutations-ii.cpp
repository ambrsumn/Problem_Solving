class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> st;
    
    void bt(int i, vector<int> &nums)
    {
        if(i>=nums.size())
        {
            st.insert(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++)
        {
            if(i!=j && nums[j]==nums[i])continue;
                
            swap(nums[i], nums[j]);
            bt(i+1,nums);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        bt(0,nums);
        
        for(auto it : st)ans.push_back(it);
        return ans;
    }
};