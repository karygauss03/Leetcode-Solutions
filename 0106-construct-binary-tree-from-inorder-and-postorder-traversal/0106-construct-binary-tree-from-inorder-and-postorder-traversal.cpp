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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return formBinaryTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode* formBinaryTree(vector<int>& inOrder, vector<int>& postOrder, int start, int end, int start2, int end2) {
        if (start > end) {
            return nullptr;
        }
        TreeNode* middle = new TreeNode(postOrder[end2]);
        int mid = 0;
        for (int i = start; i <= end; i++) {
            if (inOrder[i] == middle->val) {
                mid = i;
                break;
            }
        }
        int noOfElements = mid - 1 - start;
        int x = noOfElements + start2;
        middle->left = formBinaryTree(inOrder, postOrder, start, mid - 1, start2, x);
        middle->right = formBinaryTree(inOrder, postOrder, mid + 1, end, x + 1, end2 - 1);
        return middle;
    }
};