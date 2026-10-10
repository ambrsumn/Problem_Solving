class Solution {
public:
    
    int dp[31][1001];
    int mod = (int)(1e9+7);
    
    int recur(int i, int &k, int n, int target)
    {
        if(i == n)
        {
            if(target==0)return 1;
            return 0;
        }
        
        if(target<0)return 0;
        
        if(dp[i][target] != -1)return dp[i][target];
        int ans = 0;
        
        for(int j=1; j<=k; j++)
            ans = (ans + recur(i+1, k, n, target-j))%mod;
        
        return dp[i][target] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) 
    {
        memset(dp, -1, sizeof(dp));
        return recur(0, k, n, target);
    }
};