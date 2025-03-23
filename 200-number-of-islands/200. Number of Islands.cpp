class Solution {
public:

    void recur(int i, int j, int &rows, int &cols, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        // cout<<i<<" "<<j<<endl;
        if(i<0 || j<0 || i >= rows || j >= cols || grid[i][j] == '0')return;
        // cout<<"YES"<<endl;

        visited[i][j] = 1;
        if(i+1 <rows && visited[i+1][j] == 0)recur(i+1, j, rows, cols, grid, visited);
        if(j+1 <cols && visited[i][j+1] == 0)recur(i, j+1, rows, cols, grid, visited);
        if(i-1 >= 0 && visited[i-1][j] == 0)recur(i-1, j, rows, cols, grid, visited);
        if(j-1 >= 0 && visited[i][j-1] == 0)recur(i, j-1, rows, cols, grid, visited);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int ans = 0;

        // cout<<rows<<" "<<cols<<endl;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(visited[i][j] == 0 && grid[i][j] == '1')
                {
                    // cout<<"YES"<<endl;
                    visited[i][j] = 1;
                    ans++;
                    recur(i, j, rows, cols, grid, visited);
                }
            }
        }

        return ans;
        
    }
};