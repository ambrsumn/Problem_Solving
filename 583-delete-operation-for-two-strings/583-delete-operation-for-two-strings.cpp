class Solution {
public:
    
    int dp[501][501];
    
    int recur(int i, int j, string &s1, string &s2)
    {
        if(i<0 || j<0)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int ans=0;
        if(s1[i] == s2[j])ans = 1 + recur(i-1, j-1, s1, s2);
        
        else
        {
            ans = max(recur(i-1,j,s1,s2), recur(i,j-1,s1,s2));
        }
        
        return dp[i][j] = ans;
    }
    
    int minDistance(string s1, string s2) 
    {
        memset(dp, -1, sizeof(dp));
        int f = recur(s1.size()-1, s2.size()-1, s1, s2);
        
        return (s1.size()-f + s2.size()-f);
    }
};