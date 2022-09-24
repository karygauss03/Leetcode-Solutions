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
    void dfs(TreeNode* root, int target, int prev_sum, vector<int> curr) {
        if (!root) return;
        prev_sum += root->val;
        curr.push_back(root->val);
        
        if (prev_sum == target && !root->left && !root->right) res.push_back(curr);
        
        dfs(root->left, target, prev_sum, curr);
        dfs(root->right, target, prev_sum, curr);
        curr.pop_back();
    }
	
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum, 0, {});
        return res;
    }
    
private:
    vector<vector<int>> res;
};