class Solution {
public:
    
    int recur(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i == nums.size()-1)return 0;
        if(i>=nums.size())return 1e8;
        
        if(dp[i] != -1)return dp[i];
        
        int ans = 1e8;
        
        for(int j=nums[i]; j>=1; j--)
            ans = min(ans, (1+recur(i+j, nums, dp)));
        
        return dp[i] = ans;
    }
    
    int jump(vector<int>& nums) 
    {
        vector<int> dp(nums.size()+1, -1);
        
        return recur(0, nums, dp);
    }
};