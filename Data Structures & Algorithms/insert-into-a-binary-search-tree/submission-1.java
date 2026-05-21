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
    private void insert(TreeNode node, int val){
        if (node==null) return;
        
        boolean L = (val < node.val);
        boolean R = (node.val < val);

        if (L){
            if (node.left!=null) insert(node.left,val);
            else{
                TreeNode res = new TreeNode(val);
                node.left = res;
                return;
            }
        }
        if (R){
            if (node.right!=null) insert(node.right,val);
            else{
                TreeNode res = new TreeNode(val);
                node.right = res;
                return;
            }
        }
    }

    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root==null){
            TreeNode res = new TreeNode(val);
            return res;
        }
        insert(root,val);
        return root;
    }
}