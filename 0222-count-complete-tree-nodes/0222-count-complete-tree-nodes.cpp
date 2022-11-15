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
    void dfs(TreeNode* node){
        if (node == nullptr) return;
        ans++;
        if (node->left != nullptr) dfs(node->left);
        if (node->right != nullptr) dfs(node->right);
    }
    int countNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};