class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        map<char,int> mpp;
        
        int i=0;
        int j=0;
        int n=s.length();
        
        int len=0, curr=0;
        
        while(i<n && j<n)
        {
            if(!mpp.count(s[j]))
            {
                mpp[s[j]]++;
                j++;
                curr++;
            }
            
            else
            {
                 mpp.erase(s[i]);
                i++;
                len = max(len,curr);
                curr--;
            }
        }
        len = max(curr, len);
        
        return len;
    }
};