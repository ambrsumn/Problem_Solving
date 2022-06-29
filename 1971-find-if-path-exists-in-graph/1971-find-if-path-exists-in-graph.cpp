class Solution {
public:
    
    bool bfs(vector<vector<int>> &vec, int source, int destination)
    {
        vector<bool> visited(vec.size(), false);
        
        queue<int> pending;
        pending.push(source);
        visited[source] = true;
        
        while(!pending.empty())
        {
            int front = pending.front();
            pending.pop();
            
            if(front == destination)
                return true;
            
            for(int i=0; i<vec[front].size(); i++)
            {
                if(!visited[vec[front][i]])
                {
                    pending.push(vec[front][i]);
                    visited[vec[front][i]] = true;
                }
            }
        }
        
        return false;
    }

    void add_to_list(vector<vector<int>> &vec, int a, int b)
    {
        // cout<<"Y"<<endl;
        vec[a].push_back(b);
        vec[b].push_back(a);
    
        return;
    }
    
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<vector<int>> vec(n);
        
        for(int i=0; i<edges.size(); i++)
        {
            add_to_list(vec,edges[i][0], edges[i][1]);
        }
        
        
        return bfs(vec, source, destination);
    }
};