class Solution {
public:

    void recur(int i, vector<vector<int>>& isConnected, vector<int> &visited, int &n)
    {
        if(i >= n)return;

        for(int j=0; j<n; j++)
        {
            if(j != i && isConnected[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                recur(j, isConnected, visited, n);
            }
        }

        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<int> visited(isConnected.size(), 0);
        int n = isConnected.size();
        int ans = 0;

        for(int i=0; i<n; i++)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                recur(i, isConnected, visited, n);
                ans++;
            }
        }

        return ans;
    }
};