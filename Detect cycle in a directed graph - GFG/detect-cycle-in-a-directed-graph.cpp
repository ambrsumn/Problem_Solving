// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[], int i, vector<bool> &visited, vector<bool> &vis)
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
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<bool> visited(V, false);
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            if(dfs(adj, i, visited, vis)) return true;
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends