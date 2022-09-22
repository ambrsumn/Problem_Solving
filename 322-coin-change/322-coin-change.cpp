class Solution {
public:
    int recur(int i, int amount, vector<int>& coins,vector<vector<int>> &dp)
    {
        if(amount<0)return 1e8;
        if(amount==0)return 0;
        
        if(i==0)
        {
            if(amount%coins[i] == 0)return (amount/coins[i]);
            else return 1e8;
        }
        
        if(dp[i][amount] != -1)return dp[i][amount];
        
        int pick = 1 + recur(i, amount-coins[i], coins, dp);
        int non_pick = recur(i-1, amount, coins, dp);
        
        return dp[i][amount] = min(pick, non_pick);
    }
    
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
            
        int ans = recur(coins.size()-1, amount, coins, dp);
        
        if(ans == 1e8)return -1;
        return ans;
    }
};