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
   bool path(TreeNode* root,int v,string &p){
       if(root->val==v)return true;
       if(root->left && path(root->left,v,p)) p.push_back('L');
       else if(root->right && path(root->right,v,p)) p.push_back('R');
       return !p.empty();
   }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s,d;
        path(root,startValue,s);
        path(root,destValue,d);
        while(!s.empty() && !d.empty() && s.back()==d.back()){
            s.pop_back();
            d.pop_back();
        }
        return string(s.size(),'U')+string(rbegin(d),rend(d));
    }
};