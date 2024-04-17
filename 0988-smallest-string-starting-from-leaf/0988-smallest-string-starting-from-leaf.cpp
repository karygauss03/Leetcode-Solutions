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
    string ans = "~";
    void dfs(TreeNode* node, string path = "") {
        if (node == nullptr) {
            return;
        }
        if (node->left == nullptr && node->right == nullptr) {
            ans = min(ans, char('a' + node->val) + path);
        }
        
        dfs(node->left, char(node->val + 'a') + path);
        dfs(node->right, char(node->val + 'a') + path);
    }
    string smallestFromLeaf(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        dfs(root);
        return ans;
    }
};