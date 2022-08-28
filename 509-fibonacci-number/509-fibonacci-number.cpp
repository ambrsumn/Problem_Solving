class Solution {
public:
    
    int recur(int n, vector<int> &dp)
    {
        if(n <= 1)return n;
        
        if(dp[n] != -1)return dp[n];
        
        return dp[n] = recur(n-1,dp) + recur(n-2,dp);
    }
    
    int fib(int n) 
    {
        if(n==0)return 0;
        
        vector<int> dp(n+1, -1);
        
        
        
        // TABULATION METHOD :-
        
        dp[0]=0;
        dp[1]=1;
        
        for(int i=2; i<=n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        
        return dp[n];
        
        
        
        return recur(n, dp);
    }
};