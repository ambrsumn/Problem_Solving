class Solution {
public:
    unordered_map<int,int> mpp;
    int end=-1;
    
    bool recur(int i, int last, vector<int> &s, vector<vector<int>> &dp)
    {
        // cout<<i<<" "<<last<<endl;
        if(i == s.size()-1)return true;
        if(i>=s.size() || i<0)return false;
        
        if(dp[i][last] != -1)return dp[i][last];
        
        bool o = false, t = false, th = false;
        
        if(mpp.count(s[i]+last-1) != 0 && last != 1)o = recur(mpp[s[i]+last-1], last-1, s, dp);
        if(mpp.count(s[i]+last) != 0)t = recur(mpp[s[i]+last], last, s, dp);
        if(mpp.count(s[i]+last+1) != 0)th = recur(mpp[s[i]+last+1] , last+1, s, dp);
        
        return dp[i][last] = (o | t | th);
    }
    
    bool canCross(vector<int>& s) 
    {
        if(s[1] != 1)return false;
        
        
        for(int i=0; i<s.size(); i++)
            mpp[s[i]] = i;
        
        vector<vector<int>> dp(2001, vector<int>(2005, -1));
        
        // return false;
        return recur(1, 1, s, dp);
        
    }
};