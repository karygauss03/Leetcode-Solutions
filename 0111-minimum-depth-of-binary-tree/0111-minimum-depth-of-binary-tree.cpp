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
int dfs(TreeNode* node) {
    if (node == nullptr) return 0;
    if (node->left != nullptr && node->right != nullptr) {
        return 1 + min(dfs(node->left), dfs(node->right));
    }
    else {
        return 1 + max(dfs(node->left), dfs(node->right));
    }
}
class Solution {
public:
    int minDepth(TreeNode* root) {
        return dfs(root);
    }
};