class Solution {
public:

    int recur(int i, vector<int> &nums, vector<int> &dp)
    {
        if(i >= nums.size())return 0;

        if(dp[i] != -1)return dp[i];

        int curr = 1;

        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[j] > nums[i])curr = max(curr, 1+recur(j, nums, dp));
        }

        return dp[i] = curr;
    }

    int lengthOfLIS(vector<int>& nums) {

        int ans = 0;
        vector<int> dp(nums.size()+1, -1);

        for(int i=0; i<nums.size(); i++)ans = max(ans, recur(i, nums, dp));

        return ans;
    }
};