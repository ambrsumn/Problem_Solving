class Solution {
public:
    
    int dp[301][5001];
    
    int recur(int i, vector<int> &coins, int amount)
    {
        if(amount<0)return 0;
        if(amount == 0)return 1;
        
        if(i == coins.size())
        {
            if(amount == 0)return 1;
            return 0;
        }
        
        if(dp[i][amount] != -1)return dp[i][amount];
        
        return dp[i][amount] = recur(i, coins, amount-coins[i]) + recur(i+1, coins, amount);
    }
    
    int change(int amount, vector<int>& coins) 
    {
        memset(dp,-1,sizeof(dp));
        return recur(0, coins, amount);
    }
};