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
    bool isValidBST(TreeNode* root) {
        long int prev = (long int)INT_MIN - 1;
        stack<TreeNode*> s;
        TreeNode* current=root;  
        while(current || !s.empty()){
            while (current){
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            if (prev >= current->val){
                return false;  
            }else{
                prev = current->val;
            }
            current = current->right;
        }
        return true;
    }
};