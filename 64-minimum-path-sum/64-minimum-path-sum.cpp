class Solution {
public:
    #define ll long long
    
ll recur(int i,int j,vector<vector<int>> &grid,vector<vector<ll>> &dp)
{
    if(i<0 || j<0)return INT_MAX;
    if(i==0 && j==0)return grid[i][j];
    
    if(dp[i][j] != -1)return dp[i][j];
    
    ll left = (grid[i][j] + recur(i-1,j,grid,dp));
    ll right = (grid[i][j] + recur(i,j-1,grid,dp));
    
    return dp[i][j] = min(left,right);
}
    
    int minPathSum(vector<vector<int>>& grid) 
    {
    int n=grid.size();
    int m=grid[0].size();
    
    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    return recur(n-1,m-1,grid,dp);
    }
};