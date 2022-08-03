class Solution {
public:
    
    bool isValid(vector<vector<int>>& grid, int i, int j, int &m, int &n)
    {
        if(i>=m || i<0 || j>=n || j<0)
            return false;
        if(grid[i][j] != 1)
            return false;
        
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, false));
        queue<pair<int,int>> pending;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 2)
                {
                    pending.push({i,j});
                }
            }
        }
        
        int ans=0;
        
        while(!pending.empty())
        {
            ans++;
            int f = pending.size();
            
            for(int k=0; k<f; k++)
            {
                
            pair<int,int> front = pending.front();
            pending.pop();
            
            int i=front.first, j=front.second;
            
            if(isValid(grid, i-1, j, m, n))
            {
                grid[i-1][j] = 2;
                pending.push({i-1,j});
            }
            
            if(isValid(grid, i+1, j, m, n))
            {
                grid[i+1][j] = 2;
                pending.push({i+1,j});
            }
            
            if(isValid(grid, i, j+1, m, n))
            {
                grid[i][j+1] = 2;
                pending.push({i,j+1});
            }
            
            if(isValid(grid, i, j-1, m, n))
            {
                grid[i][j-1] = 2;
                pending.push({i,j-1});
            }
                
            }
             
        }
        
        for(auto it : grid)
        {
            for(auto itt : it)
            {
                if(itt == 1)
                {
                    ans = -1;
                    break;
                }
            }
        }
        
        if(ans>0)
            ans--;
        
        return ans;
    }
};