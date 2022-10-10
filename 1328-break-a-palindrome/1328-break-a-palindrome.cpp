class Solution {
public:
    string breakPalindrome(string p) 
    {
        int n = p.size(), flag=0;
        
        for(int i=0; i<n/2; i++)
        {
            if(p[i] != 'a')
            {
                flag=1;
                p[i]='a';
                break;
            }
        }
        
        if(n>1 && !flag)p[n-1]='b';
        
        if(n == 1)p="";
        
        return p;
    }
};