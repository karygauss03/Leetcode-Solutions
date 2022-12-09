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
    int ans = -1;
    void dfs(TreeNode* node, int mx, int mn){
        if (node == nullptr) return;
        mx = max(node->val, mx);
        mn = min(node->val, mn);
        ans = max(ans, abs(mx - mn));
        dfs(node->left, mx, mn);
        dfs(node->right, mx, mn);
    }
    int maxAncestorDiff(TreeNode* root) {
        //We need to track the max and the min element of each subtree
        dfs(root, root->val, root->val);
        return ans;
    }
};