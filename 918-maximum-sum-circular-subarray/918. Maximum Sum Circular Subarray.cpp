class Solution {
public:

    int maxSum(vector<int>& nums, int i)
    {
        int sum=0, lsum=0, rsum=0, maxi=INT_MIN;
        int n = nums.size();

        int j = (i+1)%n;

        //right sum - max possible
        while(j != i)
        {
            sum += nums[j];
            rsum = max(rsum, sum);
            
            if(sum <= 0)break;

            (j+1 >= n) ? j = (j+1)%n : j++; 
        }
        sum=0;


        if(j == i)return max(nums[i] + lsum + rsum, lsum+rsum);


        //left sum - max possible
        j = (i-1+n)%n;
        while(j != i)
        {
            sum += nums[j];
            lsum = max(lsum, sum);
            
            if(sum <= 0)break;
            
            (j-1 < 0) ? j = (j-1+n)%n : j--; 

        }


        return max({nums[i] + lsum + rsum, lsum, rsum, nums[i]});
    }

    int maxSubarraySumCircular(vector<int>& nums) {

        int maxi = INT_MIN;
        for(auto it : nums)maxi = max(maxi, it);
        if(maxi < 0)return maxi;

        int ans = INT_MIN;

        for(int i=0; i<nums.size(); i++)ans = max(ans, maxSum(nums, i));

        return ans;
        
    }
};