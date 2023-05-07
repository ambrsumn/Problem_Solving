class Solution {
public:

    int MOD = 1e9 + 7;

    int powermod(int a, int b){
        int res = 1;
        while(b){
            if(b & 1) res = 1ll * res * a % MOD;
            b /= 2;
            a = 1ll * a * a % MOD;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        
        int n = nums.size();
        int ans = 0;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            int ub = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            if(ub <= i) break;
            ans = (ans + powermod(2, ub - i - 1)) % MOD;
        }

        return ans;

    }
};