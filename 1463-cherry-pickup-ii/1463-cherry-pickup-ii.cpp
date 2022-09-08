class Solution {
public:
    
    int recur(int i, int j1, int j2, vector<vector<int>> &t, vector<vector<vector<int>>> &dp)
    {
        if(j1<0 || j2<0 || j1>=t[0].size() || j2>=t[0].size())
            return -1e8;
        
        if(i == t.size()-1)
        {
            if(j1 == j2)
                return t[i][j2];
            else
                return t[i][j1]+t[i][j2];
        }
        
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
        int ans = INT_MIN;
        
        for(int d=-1; d<=1; d++)
        {
            for(int f=-1; f<=1; f++)
            {
                int val = 0;
                
                if(j1==j2)val = t[i][j1];
                else val = t[i][j1] + t[i][j2];
                
                ans =  max(ans, (val + recur(i+1,j1+d,j2+f,t,dp)));
            }
        }
        
        return dp[i][j1][j2] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
        
        
        return recur(0,0,c-1,grid,dp);
    }
};