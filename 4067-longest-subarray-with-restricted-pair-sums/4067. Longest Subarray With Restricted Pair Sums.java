class Solution {

    public boolean isInvalid(int[] freq, int newNum) {
        for (int i = 1; i < 501; i++) {
            if (freq[i] == 0)
                continue;
            int req = newNum - i;

            if (req >= 1 && req <= 500) {
                if (req == i && freq[req] > 1)return true;
                if (req != i && freq[req] > 0)return true;
            }

            int t = newNum + i;

            if (t >= 0 && t <= 500 && freq[t] > 0)
                return true;
        }

        return false;
    }

    public int maxSubarray(int[] nums) {

        int[] freq = new int[501];

        int l = 0;
        int n = nums.length;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            while (l < i && isInvalid(freq, nums[i])) {
                freq[nums[l]]--;
                l++;
            }
            ans = Math.max(ans, (i - l + 1));
            freq[nums[i]]++;
        }

        return ans;

    }
}