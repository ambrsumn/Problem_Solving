class Solution {

    int[] dp = new int[100001];

    int recur(int i, int[] costs)
    {
        if(i == costs.length)return 0;

        if(dp[i] != 0)return dp[i];

        int ans = Integer.MAX_VALUE;

        for(int j=i+1; j<=Math.min(i+3, costs.length); j++)
        {
            int cost = costs[j-1] + (j-i)*(j-i) + recur(j, costs);
            ans = Math.min(ans, cost);
        }

        return dp[i] = ans;
    }
    public int climbStairs(int n, int[] costs) {

        return recur(0, costs);
    }
}