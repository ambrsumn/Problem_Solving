class Solution {
public:
    
    bool isPossible(vector<int> vec, long long mid, int n)
    {
       long long sum = 0;
        
        for(auto it : vec)
        {
            sum += ceil((float)it/mid);
        }
        
        if(sum <= n)
            return true;
        
        return false;
    }
    
    int minimizedMaximum(int n, vector<int>& vec) 
    {
        long long low = 1, high = 0, ans=-1;
        
        for(auto it : vec)
        {
            high += it;
        }
    
        int sum = high;
        
        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            
            if(isPossible(vec, mid, n))
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