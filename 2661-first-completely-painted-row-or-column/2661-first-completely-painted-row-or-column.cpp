class Solution 
{
public:
    
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) 
    {
        map<long long, long long> rows;
        map<long long, long long> cols;
        
        map<long long, long long> rowsum;
        map<long long, long long> colsum;
        
        
        for(int i=0; i<mat.size(); i++)
        {
            long long temp=0;
            
            for(int j=0; j<mat[0].size(); j++)
            {
                temp += mat[i][j];
                rows[mat[i][j]] = i;
                cols[mat[i][j]] = j;
            }
            
            rowsum[i]=temp;
        }
        
        for(int i=0; i<mat[0].size(); i++)
        {
            long long temp=0;
            
            for(int j=0; j<mat.size(); j++)
            {
                temp += mat[j][i];
            }
            colsum[i]=temp;
        }
         
        int i=0;
        for(i=0; i<arr.size(); i++)
        {
            int r = rows[arr[i]];
            int c = cols[arr[i]];
            
            rowsum[r] -= arr[i];
            if(rowsum[r] == 0)break; 
            
            colsum[c] -= arr[i];
            if(colsum[c] == 0)break;
        }
        
        return i;
    }
};