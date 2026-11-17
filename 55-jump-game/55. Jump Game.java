class Solution {

    public boolean recur(int i, int[] nums, int[] dp)
    {
        if(i == nums.length-1)return true;
        if(i >= nums.length)return false;

        if(dp[i] != -1)return dp[i]==0 ? false : true;
        
        int maxJumps = nums[i];

        boolean isPossible = false;

        for(int jump=1; jump<=maxJumps; jump++)
        {
            isPossible = isPossible || recur(i+jump, nums, dp);
        }

        if(isPossible)dp[i] = 1;
        else dp[i] = 0;
        return isPossible;
    }
    public boolean canJump(int[] nums) {

        int[] dp = new int[10001];
        for(int i=0; i<10001; i++)dp[i] = -1;

        return recur(0, nums, dp);
    }
}