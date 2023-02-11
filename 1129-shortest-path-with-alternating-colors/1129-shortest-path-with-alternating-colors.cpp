class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) 
    {
        vector<int> ans(n, INT_MAX);
        vector<vector<bool>> vis(n, vector<bool>(3,false));
        vector<vector<int>> r(n), b(n);
        
        for(int i=0; i<redEdges.size(); i++)
        {
            r[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        
        for(int i=0; i<blueEdges.size(); i++)
        {
            b[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        
        queue<tuple<int, int, char>> pending;
        pending.push({0, 0, '0'});
        
        while(!pending.empty())
        {
            tuple<int,int,char> top = pending.front();
            pending.pop();
            
            int node = get<0>(top);
            int len = get<1>(top);
            int color = 0;
            if(get<2>(top) == 'b')color = 1;
            
            vis[node][color] = true;
            
            ans[node] = min(ans[node], len);
            
            
            if(get<2>(top) == 'r')
            {
                for(auto it : b[node])
                {
                    if(!vis[it][1])
                    pending.push({it, len+1, 'b'});
                }
            }
            
            else if(get<2>(top) == 'b')
            {
                for(auto it : r[node])
                {
                    if(!vis[it][0])
                    pending.push({it, len+1, 'r'});
                }
            }
            
            else
            {
                for(auto it : b[node])
                {
                    if(!vis[it][1])
                    pending.push({it, len+1, 'b'});
                }
                
                for(auto it : r[node])
                {
                    if(!vis[it][0])
                    pending.push({it, len+1, 'r'});
                }
            }
        }
        
        
        for(int i=0; i<n; i++)if(ans[i] == INT_MAX)ans[i]=-1;
        
        return ans;
    }
};