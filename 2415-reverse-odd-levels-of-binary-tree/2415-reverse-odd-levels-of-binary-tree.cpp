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
    void dfs(TreeNode* u, TreeNode* v, int lvl){
        if (u == NULL && v == NULL) return;
        if (lvl&1) swap(u->val, v->val);
        dfs(u->left, v->right, lvl + 1);
        dfs(u->right, v->left, lvl + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root->left && root->right){
            dfs(root->left, root->right, 1);
        }
        return root;
    }
};