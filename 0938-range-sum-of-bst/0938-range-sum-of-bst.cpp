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
    long long sum;
    void dfs(TreeNode* node, int l, int r){
        if (node == NULL) return;
        if (node->val <= r && node->val >= l) sum += node->val;
        dfs(node->right, l, r);
        dfs(node->left, l, r);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum = 0;
        dfs(root, low, high);
        return sum;
    }
};