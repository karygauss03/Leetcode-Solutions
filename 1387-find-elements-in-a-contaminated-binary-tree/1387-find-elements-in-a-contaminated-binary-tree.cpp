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
class FindElements {
private:
    TreeNode* root;
    
    bool dfs(TreeNode* node, int target){
        if (node == NULL) return false;
        if (node->val == target) return true;
        return dfs(node->left, target) || dfs(node->right, target);
    }
public:
    FindElements(TreeNode* node) {
        root = node;
        node->val = 0;
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){
            TreeNode* par = q.front();
            q.pop();
            if (par->left != NULL){
                par->left->val = par->val * 2 + 1;
                q.push(par->left);
            }
            if (par->right != NULL){
                par->right->val = par->val * 2 + 2;
                q.push(par->right);
            }
        }
    }
    
    bool find(int target) {
        return dfs(root, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */