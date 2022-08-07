class Solution {
public:
    
    void dfs(vector<vector<int>>& board, int i, int j, int m, int n)
    {
        if(i>=m || j>=n || i<0 || j<0)
            return;
        
        if(board[i][j] != 0)
            return;
        
        board[i][j] = -1;
        
        dfs(board, i+1, j, m, n);
        dfs(board, i, j+1, m, n);
        dfs(board, i-1, j, m, n);
        dfs(board, i, j-1, m, n);
        
    }
    
//     void dfs2(vector<vector<int>>& board, int i, int j, int m, int n)
//     {
//         if(i>=m || j>=n || i<0 || j<0)
//             return;
        
//         if(board[i][j] != 0)
//             return;
        
//         board[i][j] = -1;
        
//         dfs(board, i+1, j, m, n);
//         dfs(board, i, j+1, m, n);
//         dfs(board, i-1, j, m, n);
//         dfs(board, i, j-1, m, n);
//     }
    
    
    int closedIsland(vector<vector<int>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        
      for(int i=0; i<n; i++)
      {
          if(board[0][i] == 0)
              dfs(board, 0, i, m, n);
      }
        
      for(int i=0; i<n; i++)
      {
          if(board[m-1][i] == 0)
              dfs(board, m-1, i, m, n);
      }
        
      for(int i=0; i<m; i++)
      {
          if(board[i][0] == 0)
              dfs(board, i, 0, m, n);
      }
        
      for(int i=0; i<m; i++)
      {
          if(board[i][n-1] == 0)
              dfs(board, i, n-1, m, n);
      }
        
        int ans=0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                
                if(board[i][j] == 0)
                {
                    ans++;
                    dfs(board,i,j,m,n);
                }
            }
        }
        
        return ans;
    }
};