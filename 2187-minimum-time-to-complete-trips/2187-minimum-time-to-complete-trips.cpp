class Solution {
public:
    
    bool isPossible(vector<int> vec, long long int mid, int total)
    {
        long long count = 0;
        
        for(auto it : vec)
        {
            long long int k = it;
            count += (mid/k);
        }
        
        if(count >= total)
            return true;
        
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
         long long int low = 1, high = 1e14, ans = -1;
        
        while(low <= high)
        {
            long long int mid = low + (high-low)/2;
            
            if(isPossible(time, mid, totalTrips))
            {
                ans = mid;
                high = mid-1;
            }
            
            else
                low = mid+1;
        }
        
        return ans;
    }
};