class Solution {
public:
    
    int dp[100001][5];
    int mod = (int)(1e9+7);
    
    int recur(vector<int> &nums, int i, int prev)
    {
        if(i >= nums.size())
        {
            if(prev == 2)return 1;
            return 0;
        }
        
        if(dp[i][prev] != -1)return dp[i][prev];
        
        int pick=0, np=0;
        
        if(prev == 3)
        {
            if(nums[i] == 0)
                pick = recur(nums, i+1, 0);
        }
        
        else if(prev == 0)
        {
            if(nums[i] == 0)
                pick = recur(nums, i+1, 0);
                
            else if(nums[i] == 1)
                pick = recur(nums, i+1, 1);
        }
        
        else if(prev == 1)
        {
            if(nums[i] == 1)
                pick = recur(nums, i+1, 1);
                
            else if(nums[i] == 2)
                pick = recur(nums, i+1, 2);
        }
        
        else if(prev == 2)
        {
            if(nums[i] == 2)
                pick = recur(nums, i+1, 2);
        }
        
        np = recur(nums, i+1, prev);
        
        return dp[i][prev] = (pick+np)%mod;
    }
    
    int countSpecialSubsequences(vector<int>& nums) 
    {
        memset(dp, -1, sizeof dp);
        return recur(nums, 0, 3);
    }
};