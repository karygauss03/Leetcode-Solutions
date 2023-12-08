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
    void dfs(TreeNode* root, string &ans) {
        if(!root) return;
        ans += '(' + to_string(root -> val);
        if(!root -> left && root -> right) ans += "()";
        dfs(root -> left, ans);
        dfs(root -> right, ans);
        ans += ')';
    }
public:
    string ans = "";
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        dfs(root, ans);
        return ans.substr(1, ans.size() - 2);
    }
};