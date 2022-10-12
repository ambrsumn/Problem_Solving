class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        
        int ans = INT_MIN;
        
        for(int i = 0;i<n-2;i++)
        {
            if(nums[i] + nums[i+1] <= nums[i+2])continue;
            
            else
            {
                ans = max(ans,nums[i] + nums[i+1] + nums[i+2]);
            }
        }
        
        if(ans == INT_MIN){
            return 0;
        }
        return ans;
    }
};