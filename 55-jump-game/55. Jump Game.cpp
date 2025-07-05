class Solution {
public:

bool recur(int i, vector<int> &nums, vector<int> &dp)
{
    if(i == nums.size()-1)return true;
    if(i<0 || i>=nums.size())return false;
    if(nums[i] == 0)return false;

    if(dp[i] != -1)
    {
        return dp[i];
    }

    bool canReach = false;
    for(int j=nums[i]; j>=1; j--)
    {
        canReach = (canReach || recur(i+j, nums, dp));
    }

    return dp[i] = canReach;

}
    bool canJump(vector<int>& nums) {

        vector<int> dp(nums.size()+1, -1);

        return recur(0, nums, dp);
    }
};