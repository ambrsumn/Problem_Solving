class Solution {
public:
    int climbStairs(int n) 
    {
    if (n<=3) 
    return n;

        int  n1= 3;
        int n2 = 2;
        int current = 0;
        for (int i=3;i<n;i++){
            current=n1+n2;
            n2=n1;
            n1=current;
        }

        return current;       
    }
};