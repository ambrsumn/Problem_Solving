class Solution {
public:
int n=0;
    
int recur(int i, vector<int> &dp, vector<int> &nums)
{
    if(i>=n)return 0;
    
    if(dp[i] != -1)return dp[i];
    
    //TAKE AND CALL TO ALTERNATE
    int f = nums[i] + recur(i+2, dp, nums); 
    
    //DON'T TAKE AND CALL TO NEXT
    int l = recur(i+1, dp, nums);
    
    return dp[i] = max(f,l);
    
}
    
    int rob(vector<int>& nums) 
    {
        
        n = nums.size();
        vector<int> dp(n+1, -1); 
        
        return recur(0,dp,nums);  
    }
};