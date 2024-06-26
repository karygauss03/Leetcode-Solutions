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
    void dfs(TreeNode* node, int val) {
        if (node == nullptr) {
            return;
        }
        
        if (node->val > val) {
            if (node->left == nullptr) {
                node->left = new TreeNode(val);
                return;
            }
            dfs(node->left, val);
        }
        else {
            if (node->right == nullptr) {
                node->right = new TreeNode(val);
                return;
            }
            dfs(node->right, val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        dfs(root, val);
        return root;
    }
};