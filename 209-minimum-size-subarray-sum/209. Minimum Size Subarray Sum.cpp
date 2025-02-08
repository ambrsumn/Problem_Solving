class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int i=0, j=0, currSum=0, ans=INT_MAX;

        while(i<nums.size())
        {
            if(currSum >= target)
            {
                ans = min(ans, (i-j));

                currSum -= nums[j];
                j++;
                if(ans == 1)return 1;
            }
            else 
            {
                currSum += nums[i];
                i++;
            }
        }
        while(currSum >= target && j <= i)
        {

            ans = min(ans, (i-j));
            currSum -= nums[j];
            j++;
        }

        if(ans == INT_MAX && currSum < target)return 0;
        
        return ans;

        
    }
};