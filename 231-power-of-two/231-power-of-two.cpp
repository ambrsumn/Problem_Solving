class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if(n<=0)return false;
        
        while(n>1)
        {
            int d = n%2;
            if(d>0)return false;
            
            n /= 2;
        }
        
        return true;
    }
};