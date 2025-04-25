class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {

        int j=1, n=nums.size(), last=nums[0], ans = nums.size();

        while(j<n)
        {
            int count=0;

            while(j<n && nums[j] < last)
            {
                count++;
                j++;
            }
            if(count > 0)ans -= count;

            if(j<n)last = nums[j];
            j++;
        }

        return ans;
    }
};