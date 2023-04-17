class Solution {
public:
    
    int target=0;
    map<pair<int,int>, int> mpp;
    
    int recur(int i, vector<int> &nums, int curr)
    {
        if(i>=nums.size())
        {
            if(curr == target)return 1;
            return 0;
        }
        
        if(mpp.count({i, curr}) != 0)return mpp[{i, curr}];
        
        int plus = recur(i+1, nums, curr+nums[i]);
        int minus = recur(i+1, nums, curr-nums[i]);
        
        return mpp[{i, curr}] = plus+minus;
    }
    
    int findTargetSumWays(vector<int>& nums, int t) 
    {
        target = t;
        return recur(0, nums, 0);
    }
};