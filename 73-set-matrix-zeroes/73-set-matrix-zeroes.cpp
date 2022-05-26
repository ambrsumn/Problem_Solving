class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) 
    {
        int m = arr.size();
        int n = arr[0].size();
        
        unordered_map<int, int> rows;
        unordered_map<int, int> col;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j] == 0)
                {
                    rows[i]++;
                    col[j]++;
                }
            }
        }
        
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(rows[i] >= 1 || col[j] >= 1)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }
};