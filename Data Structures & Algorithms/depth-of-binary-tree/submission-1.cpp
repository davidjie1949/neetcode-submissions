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

// Iterative Approach
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if (!root) return 0;
//         if (!root->left && !root->right) return 1;
//         int deepest = 0;

//         std::queue<TreeNode*> st;
//         st.push(root);
//         while (!st.empty()) {
//             int levelSize = st.size();
//             for (auto i = 0; i < levelSize; ++i) {
//                 TreeNode* temp = st.front();
//                 st.pop();
//                 if (temp->left) st.push(temp->left);
//                 if (temp->right) st.push(temp->right);
//             }
//             ++deepest;
//         }
//         return deepest;
//     }
// };

//Recursive Approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
};