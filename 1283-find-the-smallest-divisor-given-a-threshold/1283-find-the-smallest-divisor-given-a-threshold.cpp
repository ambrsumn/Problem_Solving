class Solution {
public:
    
    int sum(vector<int> nums, int mid, int def)
    {
        int ans=0;
        
        for(int i=0; i<nums.size(); i++)
            ans += ceil((float)nums[i]/mid);
        
        return ans;
    }
    
    
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        
        int ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            // cout<<"mid "<<mid<<" ";
            
            int summ = sum(nums, mid, threshold);
            // cout<<summ<<endl;
            if(summ <= threshold)
            {
                // cout<<"YES"<<endl;
                ans = mid;
                high = mid-1;
            }
            
            else
            {
                low = mid+1;
            }
            
        }
        
        return ans;
    }
};