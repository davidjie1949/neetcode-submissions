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
    bool isValidBST(TreeNode* root) {
        std::stack<std::tuple<TreeNode*, long, long>> st;
        st.push({root, LONG_MIN, LONG_MAX});

        while (!st.empty()) {
            auto [n, lo, hi] = st.top(); st.pop();
            if (!n) continue;

            if (n->val <= lo || n->val >= hi) return false;

            st.push({n->right, n->val, hi}); // right: must be > n->val
            st.push({n->left, lo, n->val}); // left: must be < n->val
        }

        return true;
    }
};
