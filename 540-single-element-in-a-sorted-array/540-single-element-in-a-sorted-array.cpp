class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        
        
        int low = 0, high = (n-1);
        
        while(low <= high)
        {
            if(high == low)
                return nums[low];
            
            int mid = low +(high-low)/2;
            
            cout<<nums[mid]<<endl;
            
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            
            else if(nums[mid] == nums[mid-1])
            {
                if((mid-1-low)%2 != 0)
                    high = mid-2;
                else
                    low = mid+1;
            }
            
            else if(nums[mid] == nums[mid+1])
            {
                if((high-(mid+1))%2 != 0)
                    low = mid+2;
                
                else
                    high = mid-1;
            }
        }
        
        return -1;
    }
};