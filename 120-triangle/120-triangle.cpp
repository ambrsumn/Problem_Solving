class Solution {
public:
#define ll long long

ll recur(int i,int j,int n,vector<vector<int>> &t,vector<vector<ll>>& dp)
{
    if(i>=n || j>=t[i].size())return 1e9;
    if(i==n-1)return t[i][j];
    
    if(dp[i][j] != -1)return dp[i][j];
    
    ll down = t[i][j] + recur(i+1,j,n,t,dp);
    ll rd = t[i][j] + recur(i+1,j+1,n,t,dp);
    
    return dp[i][j] = min(down,rd);
}
    
    int minimumTotal(vector<vector<int>>& t) 
    {
        int n = t.size();
        vector<vector<ll>> dp(n, vector<ll>(n,-1));
        return recur(0,0,n,t,dp);
    }
};