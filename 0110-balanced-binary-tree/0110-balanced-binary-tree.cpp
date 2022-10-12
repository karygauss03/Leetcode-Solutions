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
    pair<bool, int> dfs(TreeNode* node, int depth){
        if (!node) return {true, depth};
        pair<bool, int> left = dfs(node->left, depth + 1);
        if (!left.first) return {false, 0};
        pair<bool, int > right = dfs(node->right, depth + 1);
        if (!right.first || abs(right.second - left.second) > 1){
            return {false, 0};
        }
        return {true, max(right.second, left.second)};
    }
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root, 0).first;
    }
};