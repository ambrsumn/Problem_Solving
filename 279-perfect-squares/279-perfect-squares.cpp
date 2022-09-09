class Solution {
public:
    
    int recur(int i, int n, vector<vector<int>> &dp)
    {
        if(n<0)return 1e8;
        if(n==0)return 0;
        if((i*i)>n)return 1e8;
        
        if(dp[i][n] != -1)return dp[i][n];
        
        //PICK - NOT_PICK
        
        int pick = 1+recur(i, (n-(i*i)), dp);
        int np = recur(i+1, n, dp);
        
        return dp[i][n] = min(pick, np);
        
    }
    
    int numSquares(int n) 
    {
        vector<vector<int>> dp(101, vector<int>(10001, -1));
        return recur(1, n, dp);
    }
};