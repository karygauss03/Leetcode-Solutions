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

vector<int> ans;
map<TreeNode*, bool> vis;
void dfs(TreeNode* node){
    if (vis[node]) return;
    if (node == NULL) return;
    vis[node] = true;
    ans.push_back(node->val);
    dfs(node->left);
    dfs(node->right);
}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        ans.clear();
        
        if (root == NULL) return {};
        dfs(root);
        return ans;
    }
};