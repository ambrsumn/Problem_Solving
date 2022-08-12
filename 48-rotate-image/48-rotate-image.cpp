class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        
        vector<int> vec;
        
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                vec.push_back(matrix[i][j]);        
            }
        }
        
        
        reverse(vec.begin(), vec.end());
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                matrix[j][i] = vec.back();
                vec.pop_back();
            }
        }
        
        return;

    }
};