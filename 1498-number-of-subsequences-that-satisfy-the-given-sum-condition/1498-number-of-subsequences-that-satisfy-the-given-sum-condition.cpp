class Solution 
{
public:
    int mod = 1e9 + 7;
    int binExp(int a, int b)
    {
        int ans = 1;
        while(b)
        {
            if(b % 2 != 0)
            {
                ans = (a * 1LL* ans) % mod;
            }
            b /= 2;
            a = (a * 1LL * a) % mod;
        }
        return ans;
    }
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int cnt = 0, n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int pos = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin() - 1;
            if(pos >= i)
            {
                cnt = (cnt % mod + binExp(2, pos - i) % mod) % mod;
            }
        }
        return cnt % mod;
    }
};