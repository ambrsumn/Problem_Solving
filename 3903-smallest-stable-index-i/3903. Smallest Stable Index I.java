class Solution {
    public int firstStableIndex(int[] nums, int k) {

        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        int n = nums.length;

        int lowest = Integer.MAX_VALUE;
        int highest = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            highest = Math.max(highest, nums[i]);

            left.add(highest);
        }

        lowest = Integer.MAX_VALUE;

        for (int i = n - 1; i >= 0; i--) {
            lowest = Math.min(lowest, nums[i]);
            right.add(lowest);
        }

        Collections.reverse(right);

        for(int i=0; i<n; i++)
        {
            int st = left.get(i) - right.get(i);
            if(st <= k)return i;
        }

        return -1;
    }
}