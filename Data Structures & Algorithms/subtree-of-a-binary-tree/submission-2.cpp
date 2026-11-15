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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;

        std::stack<TreeNode*> st; // outer pre-order traversal of root
        st.push(root);

        while (!st.empty()) {
            TreeNode* n = st.top(); st.pop();

            if (n->val == subRoot->val && isSameTree(n, subRoot)) return true;

            if (n->right) st.push(n->right);
            if (n->left) st.push(n->left);
        }

        return false;
    }
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<std::pair<TreeNode*, TreeNode*>> st;
        st.push({p,q});

        while (!st.empty()) {
            auto [a, b] = st.top(); st.pop();
            if (!a && !b) continue;
            if (!a || !b || a->val != b->val) return false;
            st.push({a->right, b->right});
            st.push({a->left, b->left});
        }

        return true;
    }
};
