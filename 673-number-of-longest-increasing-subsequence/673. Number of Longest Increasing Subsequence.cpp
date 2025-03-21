class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), 1);
        vector<int> hash(nums.size(), 1);

        int maxi = -1;
        for(int i=0; i<nums.size(); i++)
        {
            // cout<<i<<endl;
            for(int j=0; j<i; j++)
            {
                if(nums[j]<nums[i] && dp[j]+1 > dp[i])
                {
                    // cout<<"YES "<<i<<endl;
                    dp[i] = dp[j]+1;
                    hash[i] = hash[j];
                }

                else if(nums[j]<nums[i] && dp[j]+1 == dp[i])hash[i] += hash[j]; 
            }

            if(dp[i] > maxi)maxi = dp[i];
        }

        // sort(dp.begin(), dp.end());

        int ans=0;
        for(int i=0; i<nums.size(); i++)
        {
            if(maxi == dp[i])
            ans += hash[i];
        }

        return ans;
    }
};