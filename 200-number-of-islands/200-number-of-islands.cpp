class Solution {
public:
    
    bool isValid(vector<vector<char>> &vec, int i, int j, int n, int m)
    {
        if(i>=0 && i<n && j>=0 && j<m && vec[i][j] == '1')
            return true;
        
        return false;
    }
    
    void dfs(vector<vector<char>> &vec, int i, int j, int n, int m)
    {
        // cout<<i<<" "<<j<<endl;
        
        vec[i][j] = '0';
        
        if(isValid(vec, i-1, j, n, m))
            dfs(vec, i-1, j, n, m);
        // cout<<"YEs"<<endl;
        if(isValid(vec, i, j+1, n, m))
            dfs(vec, i, j+1, n, m);
        
        if(isValid(vec, i, j-1, n, m))
            dfs(vec, i, j-1, n, m);
        
        if(isValid(vec, i+1, j, n, m))
            dfs(vec, i+1, j, n, m);
        
        // return;
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int count=0;
        int n = grid.size();
        int m = grid[0].size();
        
        // if(isValid(grid, 4, 0, n, m))
        // {
        //     cout<<"YES"<<endl;
        // }
            
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == '1')
                {
                    // cout<<i<<" "<<j<<endl;
                    count++;
                    dfs(grid, i, j, n, m);
                }
            }
        }
        
        return count;
    }
};