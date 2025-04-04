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
private:
    pair<TreeNode*, int> dfs(TreeNode* node) {
        if (node == nullptr) return {nullptr, 0};
        pair<TreeNode*, int> l = dfs(node->left);
        pair<TreeNode*, int> r = dfs(node->right);

        if (l.second > r.second) return {l.first, l.second + 1};
        if (l.second < r.second) return {r.first, r.second + 1};
        return {node, l.second + 1};
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};