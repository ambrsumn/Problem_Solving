class Solution {
public:
    
    void dfs(int i, vector<vector<int>> &vec, int &n, vector<bool> &vis, vector<bool> &ava)
    {
        // cout<<i<<endl;
        
        if(i>n)
            return;
        
        if(vis[i] || !ava[i])
            return;
        
        vis[i]=true;
        
        for(auto it : vec[i])
        {
            if(!ava[it])
            {
                ava[it]=true;
                
                if(!vis[it])
                dfs(it, vec, n, vis, ava);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size()-1;
        vector<bool> vis(n+1, false);
        vector<bool> ava(n+1, false);
        
        ava[0]=true;
        
        dfs(0,rooms,n,vis,ava);
        
        for(auto it : vis)
        {
            if(!it)
                return false;
        }
        
        return true;
    }
};