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
    pair<int, int> dfs(TreeNode* root){
        if (root == nullptr) return {0, 0};
        int sum = 0, cnt = 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        sum = root->val + left.first + right.first;
        cnt = left.second + right.second + 1;
        if (sum / cnt == root->val) ans++;
        return {sum, cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if (root == nullptr) return 0;
        auto x = dfs(root);
        return ans;
    }
};