class Solution {
public:
    
    int fee=0;
    int recur(int i, vector<int> &p, bool bought, vector<vector<int>> &dp)
    {
        if(i>=p.size())
            return 0;
        
        if(dp[i][bought] != -1)return dp[i][bought];
        int profit = 0;
        
        if(bought)profit = max(p[i] + recur(i+1,p,false,dp)-fee, recur(i+1,p,true,dp));
        else profit = max(recur(i+1,p,true,dp)-p[i], recur(i+1,p,false,dp));
        
        return dp[i][bought] = profit;
    }
    
    int maxProfit(vector<int> &p, int f) 
    {
        fee = f;
        vector<vector<int>> dp(p.size()+1, vector<int>(2, -1));
        return recur(0, p, false, dp);  
    }
};