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
    int goodNodes(TreeNode* root) {
        if (!root) return 0;

        int count = 0;
        std::stack<std::pair<TreeNode*, int>> st;
        st.push({root, root->val});

        while (!st.empty()) {
            auto [n, maxSoFar] = st.top(); st.pop();

            if (n->val >= maxSoFar) count++;

            int newMax = std::max(maxSoFar, n->val);
            if (n->right) st.push({n->right, newMax});
            if (n->left)  st.push({n->left,  newMax});
        }

        return count;
    }
};
