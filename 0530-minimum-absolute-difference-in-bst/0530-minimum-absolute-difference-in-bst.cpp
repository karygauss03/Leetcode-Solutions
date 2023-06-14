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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        stack<TreeNode*> stack;
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        
        while (node || !stack.empty()) {
            if (node) {
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                stack.pop();
                if (prev) {
                    minDiff = min(minDiff, node->val - prev->val);
                }
                prev = node;
                node = node->right;
            }
        }
        return minDiff;
    }
};