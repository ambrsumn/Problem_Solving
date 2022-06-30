class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int median = 0;
        
        if(n%2 == 0)
        {
            median = (nums[n/2]+nums[n/2-1])/2;
        }
        else
            median = nums[n/2];
        
        int ans=0;
        
        for(auto it : nums)
        {
            ans += abs(median-it);
        }
        
        return ans;
    }
};