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
    vector<string> ans;
    void dfs(TreeNode* node, string tmp){
        if (!node->left && !node->right){
            ans.push_back(tmp);
            tmp = "";
            return;
        }
        if (node->left) dfs(node->left, tmp + "->" + to_string(node->left->val));
        if (node->right) dfs(node->right, tmp + "->" + to_string(node->right->val));
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        string tmp = to_string(root->val);
        dfs(root, tmp);
        return ans;
    }
};