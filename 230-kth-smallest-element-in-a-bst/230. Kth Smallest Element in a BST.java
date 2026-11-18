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
    PriorityQueue<Integer> pq;

    public void recur(TreeNode root, int k)
    {
        if(root == null)return;

        pq.add(root.val);
        if(pq.size() > k)pq.poll();

        recur(root.left, k);
        recur(root.right, k);
    }

    public int kthSmallest(TreeNode root, int k) {

        pq = new PriorityQueue<>(Collections.reverseOrder());
        recur(root, k);
        return pq.poll();
    }
}