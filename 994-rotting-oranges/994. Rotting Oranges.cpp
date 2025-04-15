class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size(), ans = 0, total=0, rotten=0;
        queue<pair<int,int>> q;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)q.push({i,j});
                if(grid[i][j] == 2 || grid[i][j] == 1)total++;
            }
        }

        while(!q.empty())
        {
            int currentSize = q.size(); 
            rotten += currentSize;

            while(currentSize--)
            {
                pair<int,int> top = q.front();
                q.pop();

                int i=top.first, j=top.second;

                if(i-1 >= 0 && grid[i-1][j] == 1)
                {
                    grid[i-1][j] = 2;
                    q.push({i-1, j});
                }

                if(i+1 < n && grid[i+1][j] == 1)
                {
                    grid[i+1][j] = 2;
                    q.push({i+1, j});
                }
                if(j-1 >= 0 && grid[i][j-1] == 1)
                {
                    grid[i][j-1] = 2;
                    q.push({i, j-1});
                }
                if(j+1 < m && grid[i][j+1] == 1)
                {
                    grid[i][j+1] = 2;
                    q.push({i, j+1});
                }
            }

            if(q.size() > 0)ans++;
        }

        return total==rotten? ans : -1; 
    }
};