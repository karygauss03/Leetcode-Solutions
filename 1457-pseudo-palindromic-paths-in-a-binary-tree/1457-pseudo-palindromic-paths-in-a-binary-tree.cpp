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
    int f(TreeNode *root,vector<int> freq){
        if(!root->left && !root->right){
            freq[root->val]++;
            bool flag = false;
            for(int i = 0 ; i < 10 ; i++){
                if(freq[i] % 2 == 1){
                    if(flag) return 0;
                    else flag = true;
                }
            }
            return 1;
        }
        freq[root->val]++;
        int res = 0;
        if(root->left) res += f(root->left,freq);
        if(root->right) res += f(root->right,freq);
        return res;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        return f(root,freq);
    }
};