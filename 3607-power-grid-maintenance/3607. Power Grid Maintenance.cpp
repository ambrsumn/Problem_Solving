class Solution {
public:

    map<int, set<int>> groupNodes;
    map<int,int> nodeGroup;

    void dfs(int node, vector<vector<int>> &graph, vector<int> &vis, int &gn)
    {
        if(vis[node] == 1)return;
        vis[node] = 1;
        nodeGroup[node] = gn;
        groupNodes[gn].insert(node);

        for(auto it : graph[node])dfs(it, graph, vis, gn);
    }

    vector<int> processQueries(int c, vector<vector<int>>& cn, vector<vector<int>>& q) {

        vector<vector<int>> graph(c+1);
        vector<int> ans, vis(c+1, -1);

        for(auto it : cn)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        for(int i=1; i<=c; i++)
        {
            if(vis[i] == -1)
            {
                groupNodes[i] = set<int>();
                dfs(i, graph, vis, i);
            }
            else continue;
        }

        fill(vis.begin(), vis.end(), 1);
        for(auto it : q)
        {
            int node = it[1];

            if(it[0] == 2)
            {
                vis[node] = 0;
                int g = nodeGroup[node];
                groupNodes[g].erase(node);
            }

            else
            {
                if(vis[node] == 1)
                {
                    ans.push_back(node);
                }
                else
                {
                    int g = nodeGroup[node];

                    if(groupNodes[g].size() == 0)ans.push_back(-1);

                    else
                    {
                        auto it = groupNodes[g].begin();
                        ans.push_back(*it);
                    }
                }

            }
        }

        return ans;
        
    }
};