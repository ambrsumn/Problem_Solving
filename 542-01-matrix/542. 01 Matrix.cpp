class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size(), m = mat[0].size(), dis = 0;

        vector<vector<int>> ans(n, vector<int>(m, -1));
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {

                    ans[i][j] = 0;
                    visited[i][j] = 1;

                    if (i - 1 >= 0 && mat[i - 1][j] == 1 && visited[i-1][j] != 1) { 
                        q.push({i - 1, j});
                        visited[i-1][j] = 1;
                    }
                    if (j - 1 >= 0 && mat[i][j - 1] == 1 && visited[i][j-1] != 1) {

                        q.push({i, j - 1});
                        visited[i][j-1] = 1;

                    }
                    if (j + 1 < m && mat[i][j + 1] == 1 && visited[i][j+1] != 1) {

                        q.push({i, j + 1});
                        visited[i][j+1] = 1;

                    }
                    if (i + 1 < n && mat[i + 1][j] == 1 && visited[i+1][j] != 1) {
                        q.push({i + 1, j});
                        visited[i+1][j] = 1;
                    }
                }
            }
        }

        while (!q.empty()) {
            dis++;
            int currSize = q.size();
            cout << dis << " " << currSize << endl;

            while (currSize--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                ans[i][j] = dis;

                if (i - 1 >= 0 && mat[i - 1][j] == 1 && visited[i-1][j] != 1) { 
                    q.push({i - 1, j});
                    visited[i-1][j] = 1;
                }
                if (j - 1 >= 0 && mat[i][j - 1] == 1 && visited[i][j-1] != 1) {

                    q.push({i, j - 1});
                    visited[i][j-1] = 1;

                }
                if (j + 1 < m && mat[i][j + 1] == 1 && visited[i][j+1] != 1) {

                    q.push({i, j + 1});
                    visited[i][j+1] = 1;

                }
                if (i + 1 < n && mat[i + 1][j] == 1 && visited[i+1][j] != 1) {
                    q.push({i + 1, j});
                    visited[i+1][j] = 1;
                }
            }
        }

        return ans;
    }
};