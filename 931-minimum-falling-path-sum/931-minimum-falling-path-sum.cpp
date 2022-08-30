class Solution {
public:
#define ll long long
    
    ll recur(int i, int j, int n, vector<vector<int>> &t, vector<vector<ll>> &dp)
    {
        if(j>=n || j<0)return INT_MAX;
        if(i==n-1)return t[i][j];
        
        if(dp[i][j] != -1)return dp[i][j];
        
        ll down = t[i][j] + recur(i+1,j,n,t,dp);
        ll rd = t[i][j] + recur(i+1,j+1,n,t,dp);
        ll ld = t[i][j] + recur(i+1,j-1,n,t,dp);
        
        return dp[i][j] = min(down, min(rd, ld));
    }
    
    int minFallingPathSum(vector<vector<int>>& t) 
    {
        int n = t.size();
        
        ll ans = INT_MAX;
        vector<vector<ll>> dp(n, vector<ll>(n,-1));
        
        for(int i=0; i<n; i++)
            ans = min(ans, recur(0,i,n,t,dp));
        
        return ans;
    }
};