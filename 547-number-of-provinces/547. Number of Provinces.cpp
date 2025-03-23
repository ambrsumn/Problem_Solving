class Solution {
public:
    
    void dfs(int i, int &n, vector<vector<int>> &vec, vector<bool> &vis)
    {
        if(vis[i])
            return;
        
        vis[i] = true;
        
        for(int j=0; j<n; j++)
        {
            if(vec[i][j] == 1)
            {
                dfs(j, n, vec, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& vec) 
    {
        int n = vec.size(), count=0;
        vector<bool> vis(n, false);
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i, n, vec, vis);
            }
        }
        
        return count;
    }
};