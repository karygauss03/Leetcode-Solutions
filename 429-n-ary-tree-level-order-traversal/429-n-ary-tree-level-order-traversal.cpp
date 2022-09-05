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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vec(height(root));
        dfs(vec,root,0);
        return vec;
    }
    void dfs(vector<vector<int>>& vec,Node* root,int level)
    {
        if(!root)
            return;
        
        vec[level].push_back(root->val);
        for(auto node : root->children)
        {
            dfs(vec,node,level + 1);
        }
    }
    int height(Node* root)
    {
        if(root == nullptr)
            return 0;
        
        int mx = 0;
        for(auto node : root->children)
        {
            mx = max(mx,height(node));
        }
        return 1 + mx;
    }
};