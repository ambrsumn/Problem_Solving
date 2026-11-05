/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    Map<Pair<TreeNode, Boolean>, Integer> dp = new HashMap<>();

    public int recur(TreeNode root, boolean allowed) {
        if (root == null)
        {
            return 0;
        }

        if(root.left == null && root.right == null)
        {
            if(allowed)return root.val;
            return 0;
        }

        Pair<TreeNode, Boolean> key = new Pair<>(root, allowed);

        if(dp.containsKey(key))return dp.get(key);


        int pick = 0, np = 0;

        if (allowed)
            pick = root.val + recur(root.left, !allowed) + recur(root.right, !allowed);

        np = recur(root.left, true) + recur(root.right, true);

        dp.put(key, Math.max(pick, np));

        return dp.get(key);
    }

    public int rob(TreeNode root) {

        return recur(root, true);
    }
}

