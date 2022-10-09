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
    map<int, int> ma;
    map<TreeNode*, bool> vis;
    bool dfs(TreeNode* node, int k){
        if (node == NULL) return false;
        if (vis[node]) return false;
        vis[node] = true;
        if (ma.find(node->val) != ma.end()){
            return true;
        }
        ma[k - node->val] = 1;
        return dfs(node->left, k) || dfs(node->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);   
    }
};