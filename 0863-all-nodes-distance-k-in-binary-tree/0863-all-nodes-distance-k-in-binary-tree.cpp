/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    vector<int> adj[505];
    void fillGraph(TreeNode* node) {
        if (node == NULL) return;
        if (node->left != NULL){
            adj[node->val].push_back(node->left->val);
            adj[node->left->val].push_back(node->val);
            fillGraph(node->left);
        }
        if (node->right != NULL){
            adj[node->val].push_back(node->right->val);
            adj[node->right->val].push_back(node->val);
            fillGraph(node->right);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        for (int i = 0 ; i <= 500 ; ++i) {
            adj[i].clear();
        }
        fillGraph(root);
        queue<pair<int,int>> q;
        q.push({target->val, 0});
        set<int> s;
        s.insert(target->val);
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            if (p.second == k) {
                ans.push_back(p.first);
                continue;
            }
            for (auto &u : adj[p.first]) {
                if (s.find(u) == s.end()) {
                    s.insert(u);
                    q.push({u, p.second + 1});
                }
            }
        }
        return ans;
    }
};