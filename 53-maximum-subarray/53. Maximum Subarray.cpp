class Solution {
public:

    int maxSum(vector<int>& nums)
    {
        int sum=0, maxi=INT_MIN;

        for(auto it : nums)
        {
            sum += it;
            maxi = max(sum, maxi);

            if(sum < 0)sum=0;
        }
        return maxi;
    }
    int maxSubArray(vector<int>& nums) {

        return maxSum(nums);
    }
};