class Solution {
public:
    
    int dp[1001][1001];
    
    int recur(int i, int j, string &s1, string &s2)
    {
        if(j<0) return i+1;
        if(i<0)return j+1;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int ans = 0;
        
        if(s1[i] == s2[j])
            ans = recur(i-1, j-1, s1, s2);
        
        else
            ans = 1 + min({recur(i-1,j,s1,s2), recur(i,j-1,s1,s2), recur(i-1,j-1,s1,s2)});
        
        return dp[i][j] = ans;
    }
    
    int minDistance(string s, string t) 
    {
        if(s == t)return 0;
        
        memset(dp, -1, sizeof(dp));
        int n = s.size(), m = t.size();
        
        return recur(n-1,m-1,s,t);
    }
};