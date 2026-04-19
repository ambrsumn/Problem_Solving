class Solution {
public:
    int arrangeCoins(int n) 
    {
    int low=0,high=n;
        while(low<=high) 
        {
            long mid=low+(high-low)/2;
            if (n>=(mid*(mid+1)/2))
            { 
            low=mid+1;
            }
            else 
            high=mid-1;
        } 
        return low-1;
    }
};    
