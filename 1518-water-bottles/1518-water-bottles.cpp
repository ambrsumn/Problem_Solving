class Solution {
public:
    int numWaterBottles(int b, int e) 
    {
        int ans = 0;
        
        while(b >= e)
        {
            ans += e;
            b -= (e-1);
        }
        
        ans += b;
        return ans;
    }
};