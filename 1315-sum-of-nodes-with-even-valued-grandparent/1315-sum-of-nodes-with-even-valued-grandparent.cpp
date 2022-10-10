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
    int ans;
    map<TreeNode*, bool> vis;
    void dfs(TreeNode* node, int par = -1, int grand_par = -1){
        if (vis[node]) return;
        if (node == NULL) return;
        vis[node] = true;
        if (grand_par % 2 == 0){
            ans += node->val;
        }
        dfs(node->left, node->val, par);
        dfs(node->right, node->val, par);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};