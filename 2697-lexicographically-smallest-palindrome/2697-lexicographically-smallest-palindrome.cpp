class Solution {
public:
    string makeSmallestPalindrome(string s) 
    {
        int i=0, j=s.length()-1;
        // int count=0;
        
        while(i<j)
        {
            if(s[i] != s[j])
            {
                if(s[i] < s[j])s[j]=s[i];
                else s[i] = s[j];
                // count++;
            }
            
            i++;
            j--;
        }
        
        return s;
    }
};