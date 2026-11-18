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
    public List<Double> averageOfLevels(TreeNode root) {

        Deque<TreeNode> dq = new ArrayDeque<>();
        List<Double> ans = new ArrayList<>();

        dq.addFirst(root);

        while(!dq.isEmpty())
        {
            int currSize = dq.size();
            int temp = currSize;
            double currSum = 0.0;

            while(currSize > 0)
            {
                TreeNode curr = dq.removeFirst();
                currSum += (double)curr.val;

                if(curr.left != null)dq.addLast(curr.left);
                if(curr.right != null)dq.addLast(curr.right);

                currSize--;
            }

            ans.add(currSum / temp);
        }

        return ans;
        
    }
}