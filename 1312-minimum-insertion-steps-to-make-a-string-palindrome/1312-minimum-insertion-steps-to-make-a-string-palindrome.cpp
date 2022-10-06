class Solution {
public:
    
    int dp[1001][1001];
    
    int recur(int i1, int i2, string &s1, string &s2)
    {
        if(i1<0 || i2<0)return 0;
        
        if(dp[i1][i2] != -1)return dp[i1][i2];
        
        int ans = 0;
        
        if(s1[i1] == s2[i2]) ans = 1 + recur(i1-1, i2-1, s1, s2);
        
        else
        ans = max(recur(i1-1, i2, s1, s2), recur(i1, i2-1, s1, s2));
        
        return dp[i1][i2] = ans;
    }
    
    int minInsertions(string s1) 
    {
        memset(dp, -1, sizeof(dp));
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        
        int f = recur(s1.size()-1, s1.size()-1, s1, s2);   
        int n = s1.size();
        
        return n-f;
    }
};