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
    int cnt = 0;
    void dfs(TreeNode* node){
        if (!node) return;
        dfs(node->right);
        node->val += cnt;
        cnt = node->val;
        dfs(node->left);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }
};