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
    const static int N = 1001;
    bitset<N> rmv = 0;
    vector<TreeNode*> ans;

    void dfs(TreeNode* root, TreeNode* parent, bool isLeft) {
        if (!root) return;
        if (rmv[root->val]) {
            if (parent) {
                if (isLeft) parent->left = NULL;
                else parent->right = NULL;
            }
            dfs(root->left, NULL, 1);
            dfs(root->right, NULL, 0);
            delete root;  // Free the memory of the deleted node
        } 
        else {
            if (!parent) 
                ans.push_back(root);

            dfs(root->left, root, 1);
            dfs(root->right, root, 0);
        }
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int x : to_delete) 
            rmv[x] = 1;
        dfs(root, NULL, 1);
        return ans;
    }
};