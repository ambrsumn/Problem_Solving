class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int neg = 0;
        int pos = 0;

        sort(nums.begin(), nums.end());
        int n = nums.size();

        if(nums[n-1] < 0)
        {
            return nums[n-1] * nums[n-2] * nums[n-3];
        }

        if(nums[0] >= 0)
        {
            return nums[n-1] * nums[n-2] * nums[n-3];
        }

        for(auto it : nums)
        {
            if(it < 0)neg++;
            else pos++;
        }

        for(auto it : nums)cout<<it<<" ";

        return nums[n-1] * max((nums[0]*nums[1]), (nums[n-2]*nums[n-3]));
    }
};