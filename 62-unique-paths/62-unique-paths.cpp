class Solution {
public:
    
    int dfs(int &m, int &n, int i, int j, int &ans,vector<vector<int>>& dp)
    {
        if(i >= m || j >= n)
            return 0;
        
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        dp[i][j] = dfs(m, n, i, j+1, ans,dp) + dfs(m, n, i+1, j, ans,dp);
        
        return dp[i][j];
        
    }
    
    int uniquePaths(int m, int n) 
    {
        int ans = 0;
        vector<vector<int>> dp(m, vector<int>(n,-1));
       return dfs(m,n,0,0,ans,dp);
        
        // return dp[m-1][n-1];
    }
};