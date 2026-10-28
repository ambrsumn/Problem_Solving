class Solution {

    public int recur(int i, int rem, int[] nums, int[][] dp)
    {
        // System.out.println(i + " " + rem);
        int n = nums.length;

        if(i >= n)
        {
            return rem == 0 ? 0 : Integer.MIN_VALUE;
        }

        if(dp[i][rem] != -1)
        {
            // System.out.println("dp " + dp[i][rem]);
            return dp[i][rem];
        }

        int pick = nums[i] + recur(i+1, (rem+nums[i])%3, nums, dp);
        int np = recur(i+1, rem, nums, dp);

        dp[i][rem] = Math.max(pick, np);

        return dp[i][rem];
    }

    public int maxSumDivThree(int[] nums) {

        int n = nums.length;
        int[][] dp = new int[n+1][3];

        for(int i=0; i<n; i++)for(int j=0; j<3; j++)dp[i][j] = -1;

        return recur(0, 0, nums, dp);
    }
}
