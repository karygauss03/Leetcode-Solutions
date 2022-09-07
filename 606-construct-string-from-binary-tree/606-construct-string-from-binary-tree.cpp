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
    void preOrder(TreeNode* root,string &ans){
        if(root == NULL){
            return ;
        }
        
        // cout<<root->val;
        ans+= to_string(root->val);
        if(root->left!=NULL && root->right!=NULL){
            ans += "("; 
           preOrder(root->left,ans);
            ans += ")";  
            ans += "(";
            preOrder(root->right,ans);   
            ans += ")";
                
        }else if(root->left!=NULL){
            ans += "("; 
           preOrder(root->left,ans);
            ans += ")";
        }else if(root->right!=NULL){
            ans += "()";
            ans += "("; 
           preOrder(root->right,ans);
            ans += ")";
        }else{
            
        }
        
    }
    
    string tree2str(TreeNode* root) {
        string ans = "";
        preOrder(root,ans);
        
        return ans;
        
    }
};
