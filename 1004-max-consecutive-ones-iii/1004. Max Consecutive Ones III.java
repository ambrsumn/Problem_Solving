class Solution {
    public int longestOnes(int[] nums, int k) {

        int i = 0, j = 0;
        int n = nums.length;
        int curr = 0;
        int ans = 0;
        int last = 0;
        ArrayList<Integer> zeros = new ArrayList<>();

        for (int z = 0; z < n; z++)
            if (nums[z] == 0)
                zeros.add(z);

        while (j < n) {
            if (nums[j] != 0) {
                ans = Math.max(ans, (j - i + 1));;
                j++;
                continue;
            }

            if (nums[j] == 0) {

                if (curr == k) {
                    // ans = Math.max(ans, (j - i + 1));
                    i = zeros.get(last) + 1;
                    curr--;
                    last++;
                }

                curr++;

                if(curr <= k)ans = Math.max(ans, (j - i + 1));
                j++;
            }
        }

        return ans;

    }
}