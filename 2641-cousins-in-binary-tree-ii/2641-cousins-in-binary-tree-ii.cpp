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
    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode* temp = root;
        TreeNode* curNode;
        TreeNode* par;
        // TreeNode* dummyPar = new TreeNode(-1);
        vector<int> levelSum;
        // unordered_map<TreeNode*, int> parSum;
        queue<TreeNode*> q;
        q.push(temp);
        int n, curSum;
        while (!q.empty()) {
            n = q.size();
            curSum = 0;
            for (int i = 0; i < n; ++i) {
                curNode = q.front();
                q.pop();
                curSum += curNode->val;
                if (curNode->left != nullptr) {
                    q.push(curNode->left);
                }
                if (curNode->right != nullptr) {
                    q.push(curNode->right);
                }
            }
            levelSum.push_back(curSum);
        }
        
        temp = root;
        q.push(temp);
        temp->val = 0;
        int lvl = 1;
        while (!q.empty()) {
            n = q.size();
            for (int i = 0; i < n; ++i) {
                curNode = q.front();
                q.pop();
                int siblingSum =
                    (curNode->left ? curNode->left->val : 0) +
                    (curNode->right ? curNode->right->val : 0);
                if (curNode->left != nullptr) {
                    curNode->left->val = levelSum[lvl] - siblingSum;
                    q.push(curNode->left);
                }
                if (curNode->right != nullptr) {
                    curNode->right->val = levelSum[lvl] - siblingSum;
                    q.push(curNode->right);
                }
            }
            ++lvl;
        }
        
        return root;
    }
};