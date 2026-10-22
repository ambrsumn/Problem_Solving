class Solution {
    public int minIncrementForUnique(int[] nums) {
        int ans = 0;
        Arrays.sort(nums);
        int n = nums.length;
        int curr = nums[0];

        for(int i=0; i<n; i++)
        {
            if(nums[i] == curr)
            {
                curr++;
                continue;
            }

            if(nums[i] < curr)
            {
                ans += curr-nums[i];
                curr++;

                continue;
            }

            curr = nums[i]+1;
        }

        return ans;
    }
}