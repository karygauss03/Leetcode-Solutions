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
    int maxDepth(Node* root) {
        // edge case: empty tree
        if (!root) return 0;

        // support variables
        int level = 1, len; // level = 1, we consider the root already.
        Node *curr;

        // preparing for a BFS
        queue<Node*> q;
        for (auto n: root->children) q.push(n);
        
        len = q.size();
        while (len) {
            // updating q with a new layer of items
            for (int i = 0; i < len; i++) {
                curr = q.front();
                q.pop();
                // adding new children to the queue
                for (auto n: curr->children) q.push(n);
            }
            // updating len and level
            len = q.size();
            level++;
        }
        return level;
    }
};