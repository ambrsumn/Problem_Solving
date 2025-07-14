class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int i, vector<vector<int>> &ans, int &n, vector<int> &temp)
    {
        if(i == n)
        {
            temp.push_back(i);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        temp.push_back(i);
        
        for(auto it : graph[i])
        {
            dfs(graph, it, ans, n, temp);
        }
        
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size()-1;
        vector<vector<int>> ans;
        vector<int> temp;
        
        dfs(graph, 0, ans, n, temp);
        
        return ans;
    }
};