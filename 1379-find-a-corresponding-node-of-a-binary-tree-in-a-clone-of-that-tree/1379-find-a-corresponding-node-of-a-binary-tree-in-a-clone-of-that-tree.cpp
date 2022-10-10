/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    private:
    TreeNode* bfs(TreeNode* cloned, TreeNode* target){
        queue<TreeNode*> q;
        q.push(cloned);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp->val == target->val){
                return tmp;
            }
            if (tmp->left != NULL) q.push(tmp->left);
            if (tmp->right != NULL) q.push(tmp->right);
        }
        return cloned;
    }
    public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return bfs(cloned, target);
    }
};