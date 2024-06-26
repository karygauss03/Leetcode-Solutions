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
    void dfs(TreeNode* root, vector<TreeNode*>& values) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left, values);
        values.push_back(root);
        dfs(root->right, values);
    }
    
    TreeNode* solve(vector<TreeNode*>& values, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int mid = (left + right) / 2;
        TreeNode* root = values[mid];
        root->left = solve(values, left, mid - 1);
        root->right = solve(values, mid + 1, right);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> values;
        dfs(root, values);
        return solve(values, 0, values.size() - 1);
    }
};