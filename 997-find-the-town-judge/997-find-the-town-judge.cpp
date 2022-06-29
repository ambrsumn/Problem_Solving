class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<vector<int>> vec( n , vector<int> (n, 0));
        
        for(int i=0; i<trust.size(); i++)
        {
            int a = trust[i][0]-1;
            int b = trust[i][1]-1;
            
            vec[a][b]=1;
        }
        
        for(int i=0; i<n; i++)
        {
            int count=0;
            
            for(int j=0; j<n; j++)
            {
                if(vec[i][j] == 1)
                    break;
                count++;
            }
            
            if(count == n)
            {
                count=0;
                
                for(int k=0; k<n; k++)
                {
                    if(vec[k][i] == 1)
                        count++;
                }
                
                if(count == n-1)
                    return i+1;
            }
        }
        
        return -1;
    }
};