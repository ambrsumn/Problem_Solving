class Solution {
public:
    
    int flag = 0;
    int binary_search(vector<int> arr, int n, int target)
    {
        int low = 0, high = n-1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(arr[mid] == target)
                {
                flag = 1;
                return mid;
                }
            
            else if(arr[mid] < target)
                low = mid+1;
            
            else
                high = mid-1;
        }
        
        return low;
    }
    
    int searchInsert(vector<int>& nums, int target) 
    {
        return binary_search(nums, nums.size(), target);
        
        
    }
};