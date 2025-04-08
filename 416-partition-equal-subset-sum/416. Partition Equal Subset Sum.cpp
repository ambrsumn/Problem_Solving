class Solution {
public:

    int req=0;
    int dp[201][20001];

    bool recur(int i, int curr, vector<int>& nums)
    {
        if(i >= nums.size())return curr == req;
        if(dp[i][curr] != -1)return dp[i][curr];

        bool pick = recur(i+1, curr+nums[i], nums);
        bool np = recur(i+1, curr, nums);

        return dp[i][curr] = pick | np;
    }

    bool canPartition(vector<int>& nums) {

        int totalSum=0;
        memset(dp, -1, sizeof(dp));

        for(auto it : nums)totalSum += it;

        if(totalSum%2 != 0)return false;

        int i=0, target = totalSum/2;
        req = target;

        return recur(i, 0, nums);
    }
};