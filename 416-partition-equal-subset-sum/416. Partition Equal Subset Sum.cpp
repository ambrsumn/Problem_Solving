class Solution {
public:
    int sum=0;
    
    bool bt(int i, vector<int>& nums, int temp, vector<vector<int>> &dp)
    {
        if(temp == (sum-temp))return true;
        if(i>=nums.size() || temp>(sum-temp))return false;
        
            if(dp[i][temp] != -1)return dp[i][temp];
        
        return dp[i][temp] = bt(i+1,nums,temp+nums[i],dp) | bt(i+1,nums,temp,dp);
    }
    
    bool canPartition(vector<int>& nums) 
    {   
        for(auto it : nums)
            sum += it;
        
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        return bt(0,nums,0,dp);
    }
};