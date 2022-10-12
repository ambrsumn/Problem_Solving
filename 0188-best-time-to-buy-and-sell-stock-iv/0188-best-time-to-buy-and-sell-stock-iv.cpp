class Solution {
public:
    
    int cap = 0;
    
    int recur(int i, vector<int> &p,bool bought, int count, vector<vector<vector<int>>> &dp)
    {
        if(i>=p.size())return 0;
        if(count>=cap)return 0;
        
        if(dp[i][bought][count] != -1)return dp[i][bought][count];
        
        int price=0;
        
        if(bought)
        {
            price = max(p[i] + recur(i+1,p,false,count+1, dp), recur(i+1,p,true,count, dp));
        }
        
        else
        {
            price = max(recur(i+1,p,true,count, dp)-p[i], recur(i+1,p,false,count, dp));
        }
        
        return dp[i][bought][count] = price;
    }
    
    int maxProfit(int k, vector<int>& p) 
    {
        cap = k;
        vector<vector<vector<int>>>dp(p.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return recur(0, p, false, 0, dp);
    }
};