class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        int cnt = 0;
        
        while(start < end){
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                cnt++;
               start++;     
            }
            if(cnt > 1)
                break;
        }
        
        start = 0;
        end = s.size() - 1;
        int cnt1 = 0;
        
        while(start < end){
            if(s[start] == s[end])
            {
                start++;
                end--;  
            }
            else
            {
                cnt1++;
                end--;  
            }
            if(cnt1 > 1)
                break;
               
        }
        
        if(cnt == 1 || cnt1 == 1)   
            return true;
        if(cnt == 0 || cnt1 == 0)    
            return true;
        
        return false;
    }
};