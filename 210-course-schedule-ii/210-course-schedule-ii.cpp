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
    
    
    
    void toposort(vector<vector<int>> &grid, vector<bool> &visited, int i, vector<int> &ans)
    {
        visited[i] = true;
        
        for(int it : grid[i])
        {
            if(!visited[it])
                toposort(grid, visited, it, ans);
        }
        
        ans.push_back(i);
        return;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) 
    {
        vector<vector<int>> grid(n);
        vector<int> ans;
        
        vector<bool> visited(n, false);
        vector<bool> vis(n, false);
        
        for(int i=0; i<pre.size(); i++)
        {
            grid[pre[i][0]].push_back(pre[i][1]);
        }

        int flag = 0;
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
                if(dfs(grid, i, visited, vis)) 
                    flag = 1;
        }
        
        
        // NO CYCLE FOUND ...SO MOVING ON
        // cout<<flag<<endl;
        
        if(!flag)
        {
            // cout<<"YES"<<endl;
            vector<bool> nvis(n, false);
        
            for(int i=0; i<n; i++)
            {
                if(!nvis[i])
                    toposort(grid, nvis, i, ans);
            }
        }
        
        return ans;
    }
};