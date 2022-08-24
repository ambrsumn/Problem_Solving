class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if(n<=0)return false;
        
        while(n>1)
        {
            int d = n%3;
            if(d>0)return false;
            
            n /= 3;
        }
        
        return true;
    }
};