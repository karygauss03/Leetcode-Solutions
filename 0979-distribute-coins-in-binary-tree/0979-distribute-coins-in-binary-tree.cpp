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
    int ans = 0;
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        ans += abs(l) + abs(r);
        return node->val - 1 + l + r;
    }
    int distributeCoins(TreeNode* root) {
        int x = dfs(root);
        return ans;
    }
};