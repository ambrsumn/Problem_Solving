class Solution 
{
public:
    
    bool isPossible(vector<int> vec, int mid, int maxi)
    {
        int opt=0;
        
        for(auto it : vec)
        {
            if(it > mid)
            opt += (it-1)/mid;
        }
        
        cout<<mid<<" "<<opt<<endl;
        
        if(opt <= maxi)
            return true;
        
        return false;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        
        while(low <= high)
        {
            long long mid = low + (high - low)/2;
            
            if(isPossible(nums, mid, maxOperations))
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