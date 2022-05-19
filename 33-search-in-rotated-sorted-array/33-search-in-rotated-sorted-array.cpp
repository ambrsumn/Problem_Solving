class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int  low = 0;
        int high = n - 1;
        
        
        while(low <= high)
        {
            int mid = (low + high)/2;
            
            if(nums[mid]==target)
                return mid;
            
            if(nums[low] <= nums[mid]) // left half sorted
            {
                if(target < nums[mid] && target >= nums[low])
                {
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            
             else // right half sorted
            {
                if(target > nums[mid] && nums[high] >= target)
                {
                    low = mid + 1;
                }
                else high = mid - 1;
            }
        }
        
        return -1;
    }
};