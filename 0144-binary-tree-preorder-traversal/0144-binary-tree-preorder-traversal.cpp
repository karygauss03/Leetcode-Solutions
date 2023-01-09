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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> ans;
        for (auto cur = root; cur || !stk.empty();) {
            for (; cur; cur = cur->left) {
                ans.emplace_back(cur->val);
                stk.emplace(cur);
            }
            cur = stk.top()->right;
            stk.pop();
        }
        return ans;
    }
};