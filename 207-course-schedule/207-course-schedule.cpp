class Solution {
public:
    
    bool dfs(vector<vector<int>>& adj, int i, vector<bool> &visited, vector<bool> &vis)
    {
        visited[i] = true;
        vis[i] = true;
        
        for(auto it : adj[i])
        {
            if(!visited[it])
            {if(dfs(adj, it, visited, vis)) return true;}
            
            else if(vis[it])
            {
                // cout<<"YES"<<endl;
                return true;
            }
        }
        
        vis[i] = false;
        return false;
    }
    
    
    bool canFinish(int n, vector<vector<int>>& pre) 
    {
        vector<vector<int>> grid(n);
        
        vector<bool> visited(n, false);
        vector<bool> vis(n, false);
        
        for(int i=0; i<pre.size(); i++)
        {
            grid[pre[i][0]].push_back(pre[i][1]);
        }

        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                if(dfs(grid, i, visited, vis)) return false;
        }
        
        return true;
    }
};