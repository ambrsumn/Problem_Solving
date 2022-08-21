class Solution {
public:
    vector<vector<int>> ans;
    // set<vector<int>> st;
    
    void bt(int i, vector<int> &nums)
    {
        if(i>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            bt(i+1,nums);
            swap(nums[i], nums[j]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        bt(0,nums);
        
        // for(auto it : st)ans.push_back(it);
        
        return ans;
    }
};