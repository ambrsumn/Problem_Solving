class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {


        int st = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if(st==nums.size() || nums[st] != target)return {-1, -1};

        int end=st;
        for(int i=st; i<nums.size(); i++)
        {
            if(nums[i] == target)end = i;
            else break;
        }

        return {st, end};
    }
};