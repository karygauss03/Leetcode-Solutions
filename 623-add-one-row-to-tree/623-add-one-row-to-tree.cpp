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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
            return new TreeNode(val, root, nullptr);
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            depth--;
            int size = que.size();
            for(int n=0; n<size; n++){
                TreeNode* node = que.front();
                que.pop();
                if(depth >1){
                    if(node->left != nullptr) que.push(node->left);
                    if(node->right != nullptr) que.push(node->right);
                }else{
                    node->left = new TreeNode(val, node->left, nullptr);
                    node->right = new TreeNode(val, nullptr, node->right);
                }
            }
        }
        return root;
    }
};