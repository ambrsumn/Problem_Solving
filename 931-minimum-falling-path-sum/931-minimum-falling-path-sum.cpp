class Solution {
public:
#define ll long long
    
    // ll down=0;
    // ll rd=0;
    // ll ld=0;
    
    ll recur(int i, int j, int n, vector<vector<int>> &t, vector<vector<ll>> &dp)
    {
        // cout<<down<<" "<<rd<<" "<<ld<<endl;
        if(j>=n || j<0)return INT_MAX;
        if(i==n-1)return t[i][j];
        
        if(dp[i][j] != -1)return dp[i][j];
        // ll ans = INT_MAX;
        
        ll down = t[i][j] + recur(i+1,j,n,t,dp);
        ll rd = t[i][j] + recur(i+1,j+1,n,t,dp);
        ll ld = t[i][j] + recur(i+1,j-1,n,t,dp);
        
        // cout<<down<<" "<<rd<<" "<<ld<<endl;
        return dp[i][j] = min(down, min(rd, ld));
    }
    
    int minFallingPathSum(vector<vector<int>>& t) 
    {
        int n = t.size();
        
        ll ans = INT_MAX;
        
        for(int i=0; i<n; i++)
        {
            vector<vector<ll>> dp(n, vector<ll>(n,-1));
            ans = min(ans, recur(0,i,n,t,dp));
        }
        
        return ans;
    }
};