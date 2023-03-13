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
    bool check(TreeNode* u, TreeNode* v){
        if (!u && !v) return true;
        if (u && v){
            if (u->val != v->val) return false;
            else return check(u->left, v->right) && check(u->right, v->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};