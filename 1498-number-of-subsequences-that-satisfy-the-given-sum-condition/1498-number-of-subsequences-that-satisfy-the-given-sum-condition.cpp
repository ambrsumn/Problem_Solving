class Solution {
public:
    
    int power(int a, int b)
    {
        int res = 1;
        
        while(b)
        {
            if(b%2 != 0)
            {
                res = 1ll * res * a % mod;
            }
            
            b /= 2;
            
            a = 1ll * a * a % mod;
        }
        
        return res;
    }
    
    int mod = (int)(1e9+7);
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int ans =0;
        
        for(int i=0; i<nums.size(); i++)
        {
            int x = (target-nums[i]);
            
            int idx = upper_bound(nums.begin(), nums.end(), x) - nums.begin();
            
            idx--;
            
            long long total = (idx - i);
            
            if(total < 0)break;
            
            ans = (ans + power(2, total))%mod;
        }
        
        return ans;
    }
};