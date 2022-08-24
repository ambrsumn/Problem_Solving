class Solution {
public:
    
    bool recur(int n)
    {
        if(n<=1)return true;
        if(n<3)return false;
        
        return recur(n/3) and recur(n%3);
    }
    
    bool checkPowersOfThree(int n) 
    {
        return recur(n);
    }
};