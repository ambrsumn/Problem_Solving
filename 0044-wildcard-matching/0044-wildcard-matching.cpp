class Solution {
public:
    
    // int dp[2001][2001];
    
    bool recur(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if(i<0 && j<0)
            return true;
        
        if(j<0 && i>=0)
            return false;
        
        
        if(i<0 && j>=0)
        {
            for(int k=j;k>=0;k--)
            {
                if(s2[k]!='*')
                    return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if((s1[i] == s2[j]) || s2[j] == '?') return dp[i][j] = recur(i-1, j-1, s1, s2, dp);
        
        if(s2[j] == '*') return dp[i][j] = recur(i-1, j, s1, s2, dp) || recur(i, j-1, s1, s2, dp);
        
        
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) 
    {
         int m = s.size();
         int n = p.size();
         vector<vector<int>> dp(m,vector<int> (n,-1));
        
        return recur(s.size()-1, p.size()-1, s, p, dp);
    }
};