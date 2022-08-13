class Solution {
public:
    int n=0,m=0;
    vector<vector<bool>> vis;
    int ss=0;
    
    bool dfs(int i, int j, vector<vector<char>>& board, string & word, int indx)
    {
        // cout<<i<<j<<" "<<indx<<endl;
        if(indx == ss)return true;
        
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j])
            return false;
        
        if(board[i][j] != word[indx])
            return false;
        
        vis[i][j]=true;
        
        bool ans = dfs(i+1,j,board,word,indx+1) || dfs(i-1,j,board,word,indx+1) || dfs(i,j+1,board,word,indx+1) || dfs(i,j-1,board,word,indx+1);
        
        vis[i][j]=false;
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
        n=board.size();
        m=board[0].size();
        ss=word.size();
        
        vis.resize(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][i])
                {
                    // cout<<i<<" "<<j<<" enter "<<endl;
                    if(dfs(i,j,board, word, 0))return true;
                }
            }
        }
        
        return false;
        
    }
};