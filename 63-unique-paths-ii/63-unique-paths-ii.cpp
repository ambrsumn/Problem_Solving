class Solution {
public:
long long recur(int i,int j,int n,int m,vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if(i<0 || j<0)return 0;
    if(i>=0 && j>=0 && mat[i][j] == 1)return 0;
    if(i==0 && j==0)return 1;
    
    if(dp[i][j] != -1)return dp[i][j];
    
    return dp[i][j] = (recur(i-1,j,n,m,mat,dp) + recur(i,j-1,n,m,mat,dp));
}

    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) 
    {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return recur(n-1,m-1,n,m,mat,dp);
    }
};