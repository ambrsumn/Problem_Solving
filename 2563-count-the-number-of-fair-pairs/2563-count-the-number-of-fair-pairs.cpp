class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) 
    {
        sort(nums.begin(), nums.end());
        
        long long ans = 0;
        
        for(long long i=0; i<nums.size(); i++)
        {
            long long st = lower_bound(nums.begin(), nums.end(), (lower-nums[i])) - nums.begin();
            
            if(st <= i)st = i+1;
            if(st == nums.size())continue;
            
            long long end = lower_bound(nums.begin(), nums.end(), (upper-nums[i])) - nums.begin();
            
            
             if(end <= i)end = i+1;
            
            while(end<nums.size() && nums[end] == (upper-nums[i]))end++;
            
            if(end == nums.size())end--;
            
            if(nums[end] > (upper - nums[i]))end--;
            
            
            if(end - st >= 0)ans += (end-st+1);
            
            // cout<<nums[i]<<" "<<st<<" "<<end<<endl;
        }
        
        return ans;
    }
};