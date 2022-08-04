class Solution 
{
public:
    
    int n=0,m=0;
    
    void dfs2(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return;
        
        if(grid[i][j] == 0)
            return;
        
        grid[i][j]=0;
        
        dfs2(grid,i+1,j);
        dfs2(grid,i-1,j);
        dfs2(grid,i,j+1);
        dfs2(grid,i,j-1);
    }
    
    int numEnclaves(vector<vector<int>>& grid) 
    {
        n=grid.size();
        m=grid[0].size();
        int count=0;
        
        for(int i=0; i<n; i++)
        {
                if(grid[i][0]==1)
                dfs2(grid,i,0);
        }
        
        for(int i=0; i<n; i++)
        {
                if(grid[i][m-1]==1)
                dfs2(grid,i,m-1);
        }
        
        
        for(int i=0; i<m; i++)
        {
                if(grid[0][i]==1)
                dfs2(grid,0,i);
        }
        
        for(int i=0; i<m; i++)
        {
                if(grid[n-1][i]==1)
                dfs2(grid,n-1,i);
        }
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                    count++;
            }
        }
        
        return count;
    }
};