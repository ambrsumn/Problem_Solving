class Solution {
public:
    string longestCommonPrefix(vector<string>& ar) 
    {
        sort(ar.begin(), ar.end());
        
        string ans = ar[0];
        int n = ar.size();
        
        for(int i=1; i<n; i++)
        {
            int j=0;
            
            while(j < min(ar[i].length(), ans.length()) )
            {
                if(ans[j] != ar[i][j])
                break;
                
                j++;
            }
            
            for(int k=(ans.length()-1); k>=j; k--)
            ans.pop_back();
            
            if(ans.empty())
            break;
            
        }
        
        return ans;        
    }
};