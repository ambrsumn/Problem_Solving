class Solution {
public:
    long long coloredCells(int n) 
    {
        long long o = pow(n, 2);
        long long t = pow(n-1, 2);
        
        long long ans = o+t;
        
        return ans;
    }
};