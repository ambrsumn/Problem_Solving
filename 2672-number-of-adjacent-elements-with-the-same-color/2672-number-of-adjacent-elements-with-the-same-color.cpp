class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>> &q) 
    {
        vector<int> g(n, 0);
        vector<int> ans;
        int temp=0;
        
        for(int i=0; i<q.size(); i++)
        {
            int color = q[i][1];
            int idx = q[i][0];
            
            int prev = g[idx];
            g[idx] = color;
            
            if(prev == color)
            {
                ans.push_back(temp);
                continue;
            }
            
            if(idx > 0)
            {
                if(prev!=0 && g[idx-1] == prev)temp--;
                
                if(g[idx-1] == color)temp++;
            }
            
            if(idx < n-1)
            {
                if(prev!=0 && g[idx+1] == prev)temp--;
                
                if(g[idx+1] == color)temp++;
            }
            
            ans.push_back(temp);
            
        }
        
        return ans;
    }
};