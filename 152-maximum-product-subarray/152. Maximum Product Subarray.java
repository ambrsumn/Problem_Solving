class Solution {
    public int maxProduct(int[] nums) {

        int lastNeg = -1;
        int ans = Integer.MIN_VALUE;

        int maxL = 1, maxR = 1;

        for (int it : nums) {

            maxL *= it;
            ans = Math.max(ans, maxL);

            if (it == 0)
                maxL = 1;
        }

        for (int i = nums.length - 1; i >= 0; i--) {
            maxR *= nums[i];
            ans = Math.max(ans, maxR);

            if (nums[i] == 0)
                maxR = 1;
        }

        return ans;

    }
}