class Solution {
public:
    
    int recur(vector<int>& days, vector<int>& costs, int i, vector<int> &dp)
    {
        // cout<<i<<endl;
        if(i >= days.size())return 0;
        
        if(dp[i] != -1)return dp[i];
        
        int a=0, b=0, c=0;
        
        a = costs[0] + recur(days, costs, i+1, dp);
        
        int idx = lower_bound(days.begin(), days.end(), days[i]+7)-days.begin();
        
        b = costs[1] + recur(days, costs, idx, dp);
        
        int indx = lower_bound(days.begin(), days.end(), days[i]+30)-days.begin();
        
        c = costs[2] + recur(days, costs, indx, dp);
        
        // cout<<a<<" "<<b<<" "<<c<<endl;
        
        return dp[i] = min({a,b,c});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        vector<int> dp(days.size()+1, -1);
        
        return recur(days, costs, 0, dp);
    }
};