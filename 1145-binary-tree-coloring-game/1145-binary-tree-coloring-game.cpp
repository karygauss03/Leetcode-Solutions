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
    TreeNode* findNode(TreeNode* root,int x) {
        TreeNode* temp = NULL;
        if(root) {
            if(root->val==x)
                temp = root;
            else {
            temp = findNode(root->left,x);
            if(!temp)
            temp = findNode(root->right,x);
            }
        }
        return temp;
    }
    
    void countChildren(TreeNode* root, int &no) {
        if(root) {
            no++;
            countChildren(root->left,no);
            countChildren(root->right,no);    
        }
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        
        int left=0,right=0,parent=0,blue=0;
        TreeNode* temp = findNode(root,x); // find node
        countChildren(temp->left,left);  // count no of nodes in left subtree
        countChildren(temp->right,right); // count no of nodes in right subtree
        blue=max(left,right);
        if(temp->val!=root->val)
            parent = n-(left+right+1); // count no of nodes apart from given node's subtree
        blue=max(blue,parent);
        
        return (blue)>(n-blue);
    }
};