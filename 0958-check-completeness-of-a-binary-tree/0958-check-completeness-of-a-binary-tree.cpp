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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            if(flag && node != NULL) return false;
            if(node == NULL){
                flag = 1;
                continue;
            }
            q.push(node->left);
            q.push(node->right);
        }
        return true;

    }
};