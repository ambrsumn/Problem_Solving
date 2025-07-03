class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k == 0)return 0;
        
        int n = nums.size();
        for(auto it  : nums)if(it == 0)return ((n*(n+1))/2);

        int i=0, j=0;
        long long curr = 1;
        int ans = 0, total=0;

        while(j<n)
        {
            curr *= nums[j];

            while(curr >= k && i<=j)
            {
                total = j-i;
                // cout<<i<<" "<<j<<" "<<total<<endl;
                ans += total; 

                curr /= nums[i];
                i++;
            }

            j++;
        }

        total = j-i;
        // cout<<i<<" F "<<j<<" "<<total<<" "<<ans<<endl;
        ans += (total * (total+1))/2;

        return ans;
    }
};