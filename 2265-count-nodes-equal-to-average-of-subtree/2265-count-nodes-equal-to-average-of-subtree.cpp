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
    int cnt;
    int dfs(TreeNode* root){
        if (root == nullptr) return 0;
        cnt++;
        return root->val + dfs(root->left) + dfs(root->right);
    }
    void dfs2(TreeNode* root){
        if (root == nullptr) return;
        cnt = 0;
        int sum = dfs(root);
        if (sum / cnt == root->val){
            ans++;
        }
        dfs2(root->left);
        dfs2(root->right);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs2(root);
        return ans;
    }
};