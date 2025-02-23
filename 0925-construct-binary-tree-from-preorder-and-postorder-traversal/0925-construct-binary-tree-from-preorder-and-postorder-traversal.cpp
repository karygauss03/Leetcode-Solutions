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
private:
    TreeNode* buildTree(int preStart, int preEnd, int postStart,
                        vector<int>& preorder, vector<int>& postorderIndex) {
        if (preStart > preEnd) return nullptr;
        if (preStart == preEnd) return new TreeNode(preorder[preStart]);

        int leftRoot = preorder[preStart + 1], leftSize = postorderIndex[leftRoot] - postStart + 1;
        TreeNode* root = new TreeNode(preorder[preStart]);
        root->left = buildTree(preStart + 1, preStart + leftSize, postStart, preorder, postorderIndex);
        root->right = buildTree(preStart + leftSize + 1, preEnd, postStart + leftSize, preorder, postorderIndex);
        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        vector<int> postIdx(n + 1);
        for (int i = 0; i < n; i++) postIdx[post[i]] = i;
        return buildTree(0, n - 1, 0, pre, postIdx);
    }
};