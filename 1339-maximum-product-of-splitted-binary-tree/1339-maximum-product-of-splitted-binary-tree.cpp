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
    void getSum(TreeNode* root,long int& tot){
        if(!root) return;
        tot+=root->val;
        getSum(root->left,tot);
        getSum(root->right,tot);
    }
    long int getMaxProduct(TreeNode* root,long int tot,long int& res){
        if(!root) return 0;
        long int curSum=root->val;
        long int l=getMaxProduct(root->left,tot,res);
        long int r=getMaxProduct(root->right,tot,res);
        res=max(res,max(((long)(tot-l)*(l)),((long)(tot-r)*(r))));
        curSum+=l+r;
        return curSum;
    }
    int maxProduct(TreeNode* root) {
        if(!root) return 0;
        long int tot=0;
        getSum(root,tot);
        
        long int res = INT_MIN;
        getMaxProduct(root,tot,res);
        
        return (long)(res) % 1000000007;
    }
};