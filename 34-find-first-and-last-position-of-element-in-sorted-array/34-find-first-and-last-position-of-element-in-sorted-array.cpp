class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int low = 0;
        int high = (nums.size()-1);
        
        int ans=-1;
        
        while(low <= high)
        {
            int mid = (high+low)/2;
            
            if(nums[mid] == target)
            {
                ans = mid;
                break;
            }
            
            else if(nums[mid] < target)
            {
                low = mid+1;
            }
            
            else
                high = mid-1;
        }
        
        vector<int> arr;
        int temp = ans;
        
        if(ans == -1)
        {
            arr.push_back(-1);
            arr.push_back(-1);
        }
        
        else
        {
            while((ans-1 >= 0) && nums[ans-1] == nums[ans])
            {
                ans--;
            }
            arr.push_back(ans);
            
            ans = temp;
            
            while((ans+1 <= nums.size()-1) && nums[ans] == nums[ans+1])
            {
                ans++;
            }
            arr.push_back(ans);
        }
        
        
        return arr;
    }
};