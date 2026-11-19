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

    List<Integer> arr = new ArrayList<>();
    public void recur(TreeNode root)
    {
        if(root == null)return;
        arr.add(root.val);
        recur(root.left);
        recur(root.right);
        return;
    }
    public int getMinimumDifference(TreeNode root) {

        recur(root);
        arr.sort(Collections.reverseOrder());

        int ans = Integer.MAX_VALUE;

        for(int i=0; i<arr.size()-1; i++)
        {
            if(arr.get(i) - arr.get(i+1) < ans)ans = arr.get(i) - arr.get(i+1);
        }
        return ans;
    
    }
}