class Solution {
public:
    int mySqrt(int x) 
    {
    int low = 0;
    int high = x; 
    int ans = -1;
        while (low <= high)
        {
            long long mid =(low+high)/2;
            long long sqmid = mid*mid;
            if(sqmid==x)
            { 
            return mid;
            }
            else if(sqmid>x)
            { 
            high = mid-1;
            }
            else
            {
                ans=mid;
                low=mid+1;
            }
        }
        return ans;    
    }
};