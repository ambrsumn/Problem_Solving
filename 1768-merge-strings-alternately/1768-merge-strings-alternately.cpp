class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string ans = "";
        
        int i=0, j=0, count=0;
        
        while(i<word1.size() && j<word2.size())
        {
            if(count%2 == 0)
            {
                ans += word1[i];
                i++;
            }
            else
            {
                ans += word2[j];
                j++;
            }
            
            count++;
        }
        
        while(i<word1.size())
        {
            ans += word1[i];
            i++;
        }
        
        while(j<word2.size())
        {
            ans += word2[j];
            j++;
        }
        
        return ans;
    }
};