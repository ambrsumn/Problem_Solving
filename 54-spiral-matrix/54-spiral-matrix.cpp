class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int r=matrix.size(), c=matrix[0].size();
        vector<int> ans;
        int top=0, left=0, right=c-1, bottom=r-1;
        
        while(top<=bottom && left<=right)
        {
            for(int i=left; i<=right; i++)
            ans.push_back(matrix[top][i]);
            
            top++;
            
            for(int i=top; i<=bottom; i++)
            ans.push_back(matrix[i][right]);
            
            right--;
            
            if(top<=bottom && left<=right)
            {
                for(int i=right; i>=left; i--)
                ans.push_back(matrix[bottom][i]);
                
                bottom--;
                
                for(int i=bottom; i>=top; i--)
                ans.push_back(matrix[i][left]);
                
                left++;
            }
        }
        
        return ans;   
    }
};