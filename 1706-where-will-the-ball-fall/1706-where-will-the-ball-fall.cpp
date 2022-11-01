class Solution {
public:
    
    int n=0, m=0;
    int dp[101][101];
    
    int recur(int i, int j, vector<vector<int>> &grid)
    {
        // cout<<i<<" "<<j<<endl;
        if(i>=n)return j;
        
        // if(dp[i][j] != -3)return dp[i][j];
        
        if(grid[i][j] == 1)
        {
            // cout<<"YES"<<endl;
            if(j+1 < m && grid[i][j+1] == -1)return -1;
            if(j+1 == m)return -1;
        }
        
        if(grid[i][j] == -1)
        {
            if(j-1 >= 0 && grid[i][j-1] == 1)return -1;
            if(j-1 == -1)return -1;
        }
        
        int ans = 0;
        
        if(grid[i][j] == 1) ans = recur(i+1, j+1, grid);
        if(grid[i][j] == -1) ans = recur(i+1, j-1, grid);
        
        return  ans;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) 
    {
        memset(dp, -3, sizeof(dp));
        n = grid.size();
        m = grid[0].size();
        
        vector<int> ans;
        for(int i=0; i<grid[0].size(); i++)
        {
            int temp = recur(0, i, grid);
            ans.push_back(temp);
        }
        
        return ans;
    }
};