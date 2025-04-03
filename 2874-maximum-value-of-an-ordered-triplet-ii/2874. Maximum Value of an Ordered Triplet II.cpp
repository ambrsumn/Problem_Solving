class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n = nums.size();
        vector<int> maxPre, maxSuff;
        int maxi = -1;

        for(auto it : nums)
        {
            maxi = max(maxi, it);
            maxPre.push_back(maxi);
        }

        maxi = -1;
        reverse(nums.begin(), nums.end());

        for(auto it : nums)
        {
            maxi = max(maxi, it);
            maxSuff.push_back(maxi);
        }

        reverse(nums.begin(), nums.end());
        reverse(maxSuff.begin(), maxSuff.end());

        long long ans = 0;

        for(int i=1; i<n-1; i++)
        {
            long long temp = 0;
            if(maxPre[i-1] > nums[i]) temp = maxPre[i-1] - nums[i];

            long long temp2 = maxSuff[i+1];

            long long curr = temp* temp2;
            ans = max(ans, curr);
        }

        return ans;
    }
};