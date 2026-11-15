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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<std::pair<TreeNode*, TreeNode*>> st;
        st.push({p,q});

        while (!st.empty()) {
            // c++ 17 structure binding
            auto [a, b] = st.top(); st.pop();
            if (!a && !b) continue;                             // both null: this pair matches
            if ((!a || !b || a->val != b->val)) return false;   // only one is null, or the value different

            st.push({a->right, b->right}); // push the right pair first
            st.push({a->left, b->left});   // so the left pair is checked first
        }

        return true;
    }
};
