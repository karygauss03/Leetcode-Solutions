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
    TreeNode* recoverFromPreorder(string traversal) {
        int index = 0;
        return helper(traversal, index, 0);
    }

private:
    TreeNode* helper(const string& traversal, int& index, int depth) {
        if (index >= traversal.size()) return nullptr;
        int dashCount = 0;
        while (index + dashCount < traversal.size() &&
               traversal[index + dashCount] == '-') {
            dashCount++;
        }
        if (dashCount != depth) return nullptr;
        index += dashCount;
        int value = 0;
        while (index < traversal.size() && isdigit(traversal[index])) {
            value = value * 10 + (traversal[index] - '0');
            index++;
        }
        TreeNode* node = new TreeNode(value);
        node->left = helper(traversal, index, depth + 1);
        node->right = helper(traversal, index, depth + 1);

        return node;
    }
};