class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& b) {

        long long ans = LLONG_MIN, n=b.size(), m=b[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<tuple<int, int, int>> vec;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(pq.size() < 3)pq.push({b[i][j], i, j});

                else 
                {
                    if(get<0>(pq.top()) < b[i][j])
                    {
                        pq.pop();
                        pq.push({b[i][j], i, j});
                    }

                }
            }

            while(!pq.empty())
            {
                vec.push_back(pq.top());
                pq.pop();
            }
        }

        n = vec.size();

        for(int i=0; i<n-2; i++)
        {
            auto[val1, row1, col1] = vec[i];
            
            for(int j=i+1; j<n-1; j++)
            {
                auto[val2, row2, col2] = vec[j];
                if(row1 == row2 || col1 == col2)continue;

                for(int k=j+1; k<n; k++)
                {
                    auto[val3, row3, col3] = vec[k];
                    if(row3 == row2 || col3 == col2 || row3 == row1 || col3 == col1)continue;

                    long long currSum = 1L*val1 + 1L*val2 + 1L*val3;
                    ans = max(ans, currSum);
                }
            }
        }

        return ans;
    }
};