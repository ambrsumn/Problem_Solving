class Solution {
public:
    
    bool dfs(vector<vector<int>> &vec, vector<bool> &visited, vector<bool> &vis, int i, vector<bool> &ref)
    {
        // cout<<i<<" ";
         visited[i] = true;
         vis[i] = true;
        
        for(auto it : vec[i])
        {
            if(!visited[it])
                {if(dfs(vec, visited, vis, it, ref)) return ref[i] = true;}
            
            else if(vis[it])
            {
               return ref[i] = true;
            }
        }
        vis[i] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        
        vector<bool> visited(n, false);
        vector<bool> vis(n, false);
        vector<bool> ref(n, false);
        
        for(int i=0; i<n; i++)
        {
            fill(visited.begin(), visited.end(), false);
            // auto it = st.find(i);
            
            if(!visited[i])
            {
                // cout<<i<<" "; 
                dfs(graph, visited, vis, i, ref);
            }
        }
        // cout<<endl;
        vector<int> ans;
        
//         for(auto it : st)
//         {
//             cout<<it<<" ";
//         }
        
//         cout<<endl;
        
        for(int i=0; i<n; i++)
        {
            if(!ref[i])
                ans.push_back(i);
        }
        
        return ans;
    }
};