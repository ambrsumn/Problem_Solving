class Solution {
public:
    
    bool poss(int mid, vector<int> &nums, int k)
    {
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] <= mid)
            {
                k--;
                i += 1;
            }
            
            if(k == 0)return true;
        }
        
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) 
    {
        int low = 0;
        int high = 1e9;
        int ans=1e7;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(poss(mid, nums, k))
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