class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<int> costVec = {0, 1, 1};
    int recur(int i, int j, int cost, vector<vector<int>>& grid, int k) {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
        {
            if(cost + costVec[grid[i][j]] > k)return INT_MIN;
            return grid[i][j];
        }
        if (i >= grid.size() || j >= grid[0].size() || cost > k)
            return INT_MIN;
        
        if(dp[i][j][cost] != -1)return dp[i][j][cost];

        int ans = grid[i][j];

        int down = recur(i + 1, j, cost + costVec[grid[i][j]], grid, k);
        int right = recur(i, j+1, cost + costVec[grid[i][j]], grid, k);

        return dp[i][j][cost] = ans + max(down, right);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        dp.assign(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(1000, -1)));
        int ans = recur(0,0,0,grid,k);

        return ans < 0 ? -1 : ans;
    }
};