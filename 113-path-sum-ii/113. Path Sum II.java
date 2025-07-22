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
    
    List<List<Integer>> ans = new ArrayList<>();
    
    public void recur(TreeNode root, int targetSum, List<Integer> temp, int currSum)
    {
        if(root.left == null && root.right == null)
        {
            if(currSum + root.val == targetSum)
            {
                // System.out.println(currSum + " " + root.val);
                
                temp.add(root.val);
                ans.add(new ArrayList<>(temp)); // copy
                temp.remove(temp.size() - 1);
            }
            return;
        }

        if(root.left != null)
        {
            temp.add(root.val);
            recur(root.left, targetSum, temp, currSum+root.val);
            temp.removeLast();
        }

        if(root.right != null)
        {
            temp.add(root.val);
            recur(root.right, targetSum, temp, currSum+root.val);
            temp.removeLast();
        }

        return;
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {

        List<Integer> temp = new ArrayList<>();
        ans.clear();
        if(root == null)return ans;
        recur(root, targetSum, temp, 0);

        return ans;
    }
}