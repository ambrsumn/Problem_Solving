class Solution {
public:
    
    void dfs(vector<vector<char>>& board, int i, int j, int m, int n)
    {
        if(i>=m || j>=n || i<0 || j<0)
            return;
        
        if(board[i][j] != 'O' || board[i][j] == 'I')
            return;
        
        board[i][j] = 'I';
        
        dfs(board, i+1, j, m, n);
        dfs(board, i, j+1, m, n);
        dfs(board, i-1, j, m, n);
        dfs(board, i, j-1, m, n);
        
    }
    
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size();
        int n = board[0].size();
        
      for(int i=0; i<n; i++)
      {
          if(board[0][i] == 'O')
              dfs(board, 0, i, m, n);
      }
        
      for(int i=0; i<n; i++)
      {
          if(board[m-1][i] == 'O')
              dfs(board, m-1, i, m, n);
      }
        
      for(int i=0; i<m; i++)
      {
          if(board[i][0] == 'O')
              dfs(board, i, 0, m, n);
      }
        
      for(int i=0; i<m; i++)
      {
          if(board[i][n-1] == 'O')
              dfs(board, i, n-1, m, n);
      }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                
                if(board[i][j] == 'I')
                    board[i][j] = 'O';
            }
        }
        
    }
};