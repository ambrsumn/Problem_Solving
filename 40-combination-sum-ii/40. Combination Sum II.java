class Solution {

    List<List<Integer>> ans;

    public void recur(int i, int[] c, int target, List<Integer> curr) {
        if (0 == target) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        if (i >= c.length || target < 0)
            return;

        int n = c.length;

        while (i < n) {
            // pick
            target -= c[i];
            curr.add(c[i]);
            recur(i + 1, c, target, curr);

            // not pick
            target += c[i];
            curr.remove(curr.size() - 1);
            while (i < n - 1 && c[i + 1] == c[i])
                i++;

            // recur(i + 1, c, target, curr);
            i++;
        }

    }

    public List<List<Integer>> combinationSum2(int[] c, int target) {

        ans = new ArrayList<>();
        Arrays.sort(c);
        List<Integer> curr = new ArrayList<>();

        recur(0, c, target, curr);

        return ans;
    }
}