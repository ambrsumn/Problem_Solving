class Solution {

    int mod = (int) 1e9 + 7;

    public int recur(int i, int currSum, int n, int k, int target, int[][] dp) {
        // IO.println(i + " new call " + currSum);
        if (i > n)
            return 0;
        if (currSum > target)
            return 0;
        if (i == n && currSum == target)
            return 1;

        if(dp[i][currSum] != -1)return dp[i][currSum];

        int ways = 0;

        // IO.println("coming to " + i);
        for (int j = 1; j <= k; j++) {

            // IO.println("selecting " + i + " " + j);
            currSum += j;
            ways = (ways % mod + recur(i + 1, currSum, n, k, target, dp) % mod) % mod;
            currSum -= j;
        }

        return dp[i][currSum] = ways;
    }

    public int numRollsToTarget(int n, int k, int target) {

        int[][] dp = new int[n + 1][1001];

        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < 1001; j++)
                dp[i][j] = -1;

        return recur(0, 0, n, k, target, dp);

    }
}