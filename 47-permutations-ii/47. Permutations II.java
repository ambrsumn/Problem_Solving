class Solution {

    Set<List<Integer>> ans;

    public void recur(int i, int[] nums, int[] vis, List<Integer> curr) {

        if (curr.size() == nums.length) {
            ans.add(new ArrayList<>(curr));
            return;
        }

        for (int k = 0; k < nums.length; k++) {
            if (vis[k] == 0) {
                vis[k] = 1;
                curr.add(nums[k]);
                recur(k, nums, vis, curr);
                vis[k] = 0;
                curr.remove(curr.size() - 1);
            }
        }

    }

    public List<List<Integer>> permuteUnique(int[] nums) {

        ans = new HashSet<>();
        int[] vis = new int[nums.length];
        Arrays.sort(nums);
        List<Integer> curr = new ArrayList<>();
        recur(0, nums, vis, curr);

        return new ArrayList<>(ans);
    }
}