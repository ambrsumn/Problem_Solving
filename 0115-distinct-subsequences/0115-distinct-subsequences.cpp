class Solution {
public:
    
    int dp[1001][1001];
    
    int recur(int i, int j, string &s1, string &s2)
    {
        if(j<0) return 1;
        if(i<0)return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int ans = 0;
        
        if(s1[i] == s2[j])
            ans = recur(i-1, j-1, s1, s2) + recur(i-1, j, s1, s2);
        else
        ans = recur(i-1, j, s1, s2);
        
        return dp[i][j] = ans;
    }
    
    int numDistinct(string s, string t) 
    {
        memset(dp, -1, sizeof(dp));
        
        int n = s.size(), m = t.size();
        
        return recur(n-1,m-1,s,t);
    }
};