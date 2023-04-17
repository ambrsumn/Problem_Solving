class Solution {
public:
    
    int target=0;
    
    int recur(int i, vector<int> &nums, int curr)
    {
        // cout<<i<<" "<<curr<<endl;
        if(i>=nums.size())
        {
            if(curr == target)return 1;
            return 0;
        }
        
        int plus = recur(i+1, nums, curr+nums[i]);
        int minus = recur(i+1, nums, curr-nums[i]);
        
        return plus+minus;
    }
    
    int findTargetSumWays(vector<int>& nums, int t) 
    {
        target = t;
        return recur(0, nums, 0);
    }
};