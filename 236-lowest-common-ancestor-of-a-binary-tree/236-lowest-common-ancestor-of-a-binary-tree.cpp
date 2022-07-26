class Solution {
public:
    TreeNode* res;
    bool rec(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        
        int in_left = rec(root->left, p, q);
        int in_right = rec(root->right, p, q);
        int curr = (root == p) || (root == q);
        
        if ((in_left && in_right) || (in_left && curr) || (in_right && curr))
            res = root;
        
        return in_left || in_right || curr;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        rec(root, p, q);
        return res;
    }
    
};