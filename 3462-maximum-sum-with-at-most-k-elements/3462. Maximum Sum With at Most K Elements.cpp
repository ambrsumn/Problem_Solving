class Solution {
public:

    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {


        for(int i=0; i<grid.size(); i++)
        {
            sort(grid[i].begin(), grid[i].end(), greater<int>());

        }
        priority_queue<int> pq;


        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++)
        {
            int temp = limits[i];

            for(int j=0; j<m; j++)
            {
                if(temp == 0)break;
                pq.push(grid[i][j]);
                temp--;
            }
        }

        long long ans = 0;

        while(!pq.empty() && k--)
        {
            ans += pq.top();
            pq.pop();
        }

        return ans;
        
    }
};