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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
// Base cases to check if there is no root node
        if(!root) return root;
// or else if there are no leaf nodes to the root node and thus we simply check if the root node is less than the limit or not, if it is less we return null or else we know what to return.
        if(!root->left && !root->right){
            if(root->val < limit) return NULL;
            else return root;
        } else {
// We then start out DFS traversal, every time decreasing the limit with the current node's value and after that, we move over ahead and check the base conditions again and see if any case has been satisfied or not
            root->left = sufficientSubset(root->left, limit-root->val);
            root->right = sufficientSubset(root->right, limit-root->val);
            
            if(!root->left && !root->right) return NULL;
            else return root;
        }
    }
};