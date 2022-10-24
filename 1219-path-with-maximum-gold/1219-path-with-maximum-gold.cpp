class Solution {
public:
    
    int row=0, col=0;
    // int dp[16][16];
    
    int recur(int i, int j, vector<vector<int>> &grid)
    {
        if(i<0 || i>=row || j<0 || j>=col)return 0;
        if(grid[i][j] == 0)return 0;
        
        int temp = grid[i][j];
        grid[i][j] = 0;
        
        int top = recur(i-1, j, grid);
        int bottom = recur(i+1, j, grid);
        int left = recur(i, j-1, grid);
        int right = recur(i, j+1, grid);
        
        grid[i][j] = temp;
        int ans = temp + max({top, bottom, left, right});
        
        return ans;
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) 
    {
        row = grid.size();
        col = grid[0].size();
        
        int ans = INT_MIN;
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                if(grid[i][j] != 0)
                    ans = max(ans, recur(i, j, grid));
            }
        }
        
        return ans<0 ? 0 : ans;
    }
};