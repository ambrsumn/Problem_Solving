class Solution {

    List<List<Integer>> ans;

    public void recur(int i, int[] c, int target, List<Integer> curr, int k) {
        if (0 == target && curr.size() == k) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        if (i >= c.length || target < 0 || curr.size() >= k)
            return;

        int n = c.length;

        while (i < n) {
            // pick
            target -= c[i];
            curr.add(c[i]);
            recur(i + 1, c, target, curr, k);

            // not pick
            target += c[i];
            curr.remove(curr.size() - 1);
            while (i < n - 1 && c[i + 1] == c[i])
                i++;

            // recur(i + 1, c, target, curr);
            i++;
        }

    }

    public List<List<Integer>> combinationSum3(int k, int n) {

        int[] c = new int[9];
        for(int i=0; i<9; i++)c[i] = i+1;

        ans = new ArrayList<>();
        Arrays.sort(c);
        List<Integer> curr = new ArrayList<>();

        recur(0, c, n, curr, k);

        return ans;
    }
}