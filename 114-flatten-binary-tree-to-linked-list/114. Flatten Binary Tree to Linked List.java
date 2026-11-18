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

    // TreeNode head = null;
    // TreeNode temp = null;

    public void recur(TreeNode root) {
        if (root == null)
            return;
        // IO.println(root.val);

        // TreeNode newNode = new TreeNode(root.val);
        // newNode.left = null;
        // newNode.right = null;

        // if(head == null)
        // {
        //     head = newNode;
        //     temp = head;
        // } 
        // else 
        // {
        //     temp.right = newNode;
        //     temp = newNode;
        // }

        recur(root.left);
        recur(root.right);

        if (root.left != null && root.right != null) {

            TreeNode lastNode = root.left;
            while(lastNode.right != null)lastNode = lastNode.right;

            lastNode.right = root.right;
            root.right = root.left;
            root.left = null;
        }

        else if(root.left != null)
        {
            root.right = root.left;
            root.left = null;
        }

        return;
    }

    // public void printTree(TreeNode root) {
    //     if (root == null) {
    //         // IO.print(" null ");
    //         return;
    //     }

    //     IO.print(root.val);
    //     printTree(root.left);
    //     printTree(root.right);
    // }

    public void flatten(TreeNode root) {

        recur(root);
        // root = head;
        // printTree(root);
    }
}