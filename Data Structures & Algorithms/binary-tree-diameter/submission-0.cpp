/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxDiameter;
    }

private:
    int depth(TreeNode* node) {
        if (!node) return 0;

        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        // Update the global maximum diameter using the path passing through this node
        maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);

        // Return the heigh/depth of this subtree to its parent
        return std::max(leftDepth, rightDepth) + 1;
    }
    int maxDiameter = 0;
};
