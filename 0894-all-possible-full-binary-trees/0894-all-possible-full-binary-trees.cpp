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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (!(n & 1)) 
            return {};
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0] = {};
        dp[1] = {new TreeNode(0)};
        for (int i = 2 ; i <= n ; ++i){
            vector<TreeNode*> ans;
            for (int j = 1; j <= i; ++j) {
                vector<TreeNode*> left = dp[j - 1];
                vector<TreeNode*> right = dp[i - j];
                for (auto &l : left) {
                    for (auto &r : right) {
                        TreeNode* root = new TreeNode(0);
                        root->left = l;
                        root->right = r;
                        ans.push_back(root);
                    }
                }
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};