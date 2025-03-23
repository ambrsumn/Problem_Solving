class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int> graph;
        int n = isConnected.size();
        vector<int> visited(n, 0);
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                graph.push(i);
                ans ++;
            }

            while(!graph.empty())
            {
                int curr = graph.front();
                graph.pop();

                for(int j=0; j<n; j++)
                {
                    if(isConnected[curr][j] == 1 && visited[j] == 0 && curr != j)
                    {
                        visited[j] = 1;
                        graph.push(j);
                    }
                }
            }
        }

        return ans;
    }
};