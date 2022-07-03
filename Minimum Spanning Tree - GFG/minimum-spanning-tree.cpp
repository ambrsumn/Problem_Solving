// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int res = 0;
        
        vector<bool> mset(n,0);
        vector<int> key(n,0);
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0; i<n; i++)
        {
            key[i] = INT_MAX;
            mset[i] = false;
        }
        
        key[0]=0;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int mini = INT_MAX, u;
            
            u = pq.top().second;
            pq.pop();
            // cout<<u<<" ";
            mset[u] = true;
            // res += key[u];
            
            for(auto it : adj[u])
            {
                if(!mset[it[0]] && it[1] < key[it[0]])
                {
                    key[it[0]] = it[1];
                    pq.push({key[it[0]], it[0]});
                }
            }
        }
        
        for(auto it : key)
        res += it;
        
        
        return res;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends