class Solution {
public:
    
    int dp[201][201];
    
    int recur(int i, int j, int &n, vector<vector<int>> &grid)
    {
        if(i>=n)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int ans = grid[i][j];
        int adder = 1e8;
        
        for(int k=0; k<n; k++)
        {
            if(k != j)
                adder = min(adder, recur(i+1,k,n,grid));
        }
        
        if(adder == 1e8)adder=0;
        
        return dp[i][j] = (ans+adder);
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        memset(dp, -1, sizeof(dp));
        
        int ans = INT_MAX;
        int n = grid.size();
        
        for(int i=0; i<n; i++)
            ans = min(ans, recur(0,i,n,grid));
        
        return ans;
    }
};