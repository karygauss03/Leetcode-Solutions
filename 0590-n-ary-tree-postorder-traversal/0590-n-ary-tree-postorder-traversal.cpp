/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    vector<int> ans;
    void dfs(Node* node){
        if (node == nullptr) return;
        for (auto &child : node->children){
            if (child != nullptr){
                dfs(child);
                ans.push_back(child->val);
            }
        }
    }
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) return ans;
        dfs(root);
        ans.push_back(root->val);
        return ans;
    }
};