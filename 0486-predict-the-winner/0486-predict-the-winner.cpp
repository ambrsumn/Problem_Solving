class Solution {
public:
    
    bool recur(vector<int> &nums, int i, int j, int count, int one, int two)
    {
        if (i > j)
        {
            if(one >= two)return true;
            return false;
        }
        
        int ans = false;

        if (count%2 == 0)
        {
            ans = recur(nums, i+1, j, count+1, one+nums[i], two) || recur(nums, i, j-1, count+1, one+nums[j], two);
        }
        
        else
        {
            ans = recur(nums, i+1, j, count+1, one, two+nums[i]) && recur(nums, i, j-1, count+1, one, two+nums[j]);
        }

        return ans;
    }
    
    bool PredictTheWinner(vector<int>& nums) 
    {
        return recur(nums, 0, nums.size()-1, 0, 0, 0);
    }
};