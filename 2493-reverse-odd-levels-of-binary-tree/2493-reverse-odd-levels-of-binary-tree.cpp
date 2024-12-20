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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        vector<TreeNode*> nodes;
        while(!q.empty()) {
            int sz = q.size();
            nodes.clear();
            for (int i = 0; i < sz; ++i) {
                TreeNode* cur = q.front();
                nodes.push_back(cur);
                q.pop();
                if (cur-> left == nullptr && cur->right == nullptr) continue;
                q.push(cur->left);
                q.push(cur->right);
            }
            if (lvl & 1) {
                int l = 0, r = nodes.size() - 1;
                while (l < r) {
                    swap(nodes[l++]->val, nodes[r--]->val);
                }
            }
            ++lvl;
        }
        return root;
    }
};