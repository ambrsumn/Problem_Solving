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
    public TreeNode invertTree(TreeNode root) {

        if (root == null)
            return root;

        List<List<TreeNode>> tree = new ArrayList<>();
        tree.add(new ArrayList<>(Arrays.asList(root)));

        Deque<TreeNode> q = new ArrayDeque<>();
        q.addFirst(root);

        while (!q.isEmpty()) {
            List<TreeNode> curr = new ArrayList<>();

            int currSize = q.size();

            while (currSize > 0) {
                TreeNode top = q.removeFirst();
                if (top == null)
                    continue;

                if (top.left != null) {
                    curr.add(top.left);
                    q.addLast(top.left);

                } else {
                    curr.add(top.left);

                }

                if (top.right != null) {
                    curr.add(top.right);
                    q.addLast(top.right);

                } else {
                    curr.add(null);
                }

                currSize--;
            }

            Collections.reverse(curr);

            tree.add(curr);
        }

        for(int i=0; i<tree.size()-1; i++)
        {
            List<TreeNode> curr = tree.get(i);
            List<TreeNode> child = tree.get(i+1);
            int j=0;
            for(TreeNode node : curr)
            {
                if(node == null)continue;

                node.left = null;
                node.right = null;

                node.left = child.get(j);
                j++;
                node.right = child.get(j);
                j++;
            }
        }

        return root;
    }
}