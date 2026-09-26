class Solution {

    Set<List<Integer>> st = new HashSet<>();
    List<Integer> prev = new ArrayList<>();

    public void recur(int i, int[] nums) {
        if (i >= nums.length)
            return;

        // IO.println(i + " prev " + prev);

        // recur(i + 1, nums, prev);
        // recur(i + 1, nums, curr);

        for (int k = i; k < nums.length; k++) {
            //pick
            prev.add(nums[k]);
            st.add(new ArrayList<>(prev));
            recur(k+1, nums);

            // not pick
            prev.remove(prev.size()-1);
            recur(k+1, nums);
        }
    }

    public List<List<Integer>> subsets(int[] nums) {
        st.add(new ArrayList<>());
        recur(0, nums);

        IO.println(st);
        List<List<Integer>> ans = new ArrayList<>(st);
        return ans;
    }
}