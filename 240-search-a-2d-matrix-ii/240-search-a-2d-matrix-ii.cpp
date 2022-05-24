class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i=(m-1), j=0;
        
        while(i>=0 && j<=n-1 && i<=m && j>=0)
        {
            // cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
            
            if(matrix[i][j] == target)
                return true;
            
            else if(matrix[i][j] > target)
            {
                i--;
            }
            
            else
                j++;
        }
        
        return false;
        
    }
};