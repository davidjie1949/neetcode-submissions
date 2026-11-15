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
// Recursive Approach
// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         depth(root);
//         return maxDiameter;
//     }

// private:
//     int depth(TreeNode* node) {
//         if (!node) return 0;

//         int leftDepth = depth(node->left);
//         int rightDepth = depth(node->right);

//         // Update the global maximum diameter using the path passing through this node
//         maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);

//         // Return the heigh/depth of this subtree to its parent
//         return std::max(leftDepth, rightDepth) + 1;
//     }
//     int maxDiameter = 0;
// };

// Iterative Approach
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int maxDiameter = 0;
        std::unordered_map<TreeNode*, int> depthMap;
        std::stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;

        while (current || !st.empty()) {
            // 1. Go as far left as possible
            while (current) {
                st.push(current);
                current = current->left;
            }

            TreeNode* peekNode = st.top(); // peek, don't pop yet

            // 2. If right child exists and hasn't been visited yet, go right
            if (peekNode->right && peekNode->right != lastVisited) {
                current = peekNode->right; // 2a. right side not done yet: go there
            } else {
                // 3. Process the node (both left and right subtrees are done)
                int leftDepth = peekNode->left ? depthMap[peekNode->left] : 0;
                int rightDepth = peekNode->right ? depthMap[peekNode->right] : 0;

                maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);
                depthMap[peekNode] = std::max(leftDepth, rightDepth) + 1;
                // 2b. both sides done: visit
                st.pop();
                lastVisited = peekNode;
            }
        }

        return maxDiameter;
    }

};
