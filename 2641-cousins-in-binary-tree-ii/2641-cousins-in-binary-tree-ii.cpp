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
struct TreeNodeHash {
    std::size_t operator()(const TreeNode* node) const {
        return reinterpret_cast<std::size_t>(node);  // Use the pointer address for hashing
    }
};

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode* temp = root;
        TreeNode* curNode;
        TreeNode* par;
        TreeNode* dummyPar = new TreeNode(-1);
        vector<int> levelSum;
        unordered_map<TreeNode*, int, TreeNodeHash> parSum;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({temp, dummyPar});
        int n, curSum;
        while (!q.empty()) {
            n = q.size();
            curSum = 0;
            for (int i = 0; i < n; ++i) {
                curNode = q.front().first;
                par = q.front().second;
                q.pop();
                curSum += curNode->val;
                // cout << curNode->val << endl;
                // cout << par->val << endl;
                parSum[par] += curNode->val;
                // cout << parSum[par] << endl;
                if (curNode->left != nullptr) {
                    q.push({curNode->left, curNode});
                }
                if (curNode->right != nullptr) {
                    q.push({curNode->right, curNode});
                }
            }
            levelSum.push_back(curSum);
        }
        
        temp = root;
        q.push({temp, dummyPar});
        int lvl = 0;
        while (!q.empty()) {
            n = q.size();
            for (int i = 0; i < n; ++i) {
                curNode = q.front().first;
                par = q.front().second;
                q.pop();
                // cout << curNode->val << " " << par->val << " " << lvl << " " << levelSum[lvl] << " " << parSum[par] << endl;
                if (curNode->left != nullptr) {
                    q.push({curNode->left, curNode});
                }
                if (curNode->right != nullptr) {
                    q.push({curNode->right, curNode});
                }
                curNode->val = max(0, levelSum[lvl] - parSum[par]);
            }
            ++lvl;
        }
        
        return root;
    }
};