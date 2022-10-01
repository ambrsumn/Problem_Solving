class Solution {
public:
    
    int dp[101];
    
    int recur(string s, int i)
    {
        if(i >= s.size())return 1;
        
        if(s[i] == '0')return 0;
        
        if(dp[i] != -1)return dp[i];
        
        int po=0, pt=0;
        
        po = recur(s, i+1);
        
        int curr = 0;
        
        if(i+1 < s.size())
        {
            curr = (s[i]-'0')*10 + (s[i+1]-'0');
            
            if(curr <= 26 && curr >= 1)pt = recur(s, i+2);
        }
        return dp[i] = (po + pt);
    }
    
    int numDecodings(string s) 
    {
        // CHECKING LEADING OR CONSECUTIVE ZEROS
        memset(dp, -1, sizeof(dp));
        int count=1;
        
        for(int i=0; i<s.size(); i++)
        {
            if(count==1 && s[i] == '0')return 0;
            
            if(s[i] != '0')count=0;
            if(s[i] == '0')count=1;
        }
        
        
        return recur(s, 0);
    }
};