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
    void dfs(TreeNode* node, vector<string>& paths, string path = "") {
        if (node == nullptr) {
            return;
        }
        path += 'a' + node->val;
        if (node->left == nullptr && node->right == nullptr) {
            reverse(path.begin(), path.end());
            paths.push_back(path);
            return;
        }
        dfs(node->left, paths, path);
        dfs(node->right, paths, path);
    }
    string smallestFromLeaf(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        vector<string> paths;
        dfs(root, paths);
        sort(paths.begin(), paths.end());
        return paths[0];
    }
};