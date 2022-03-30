class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        
        int i=0, j=(n-1);
        
        while(i < m )
        {
            
            if(matrix[i][j] == target || matrix[i][0] == target)
                return true;
            
            
            else if(matrix[i][0] > target)
                return false;
            
            
            else if(matrix[i][j] < target)
            {
                i++;
            }
            
            
            else
            {
                int k=0;
                
                while(k <= j)
                {
                    
                    int mid = (k+j)/2;
                    
                    if(matrix[i][mid] == target)
                        return true;
                    
                    
                    if(matrix[i][mid] < target)
                    {
                        k = (mid+1);
                    }
                    
                    else
                        j = (mid-1);
                    
                }
                
                if(k > j)
                    return false;
            }
        }
        
        return false;
    }
};