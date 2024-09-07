/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
private:
    bool dfs(TreeNode* treeNode, ListNode* listNode) {
        if (listNode == nullptr) {
            return true;
        }

        if (treeNode == nullptr) {
            return false;
        }
        
        if (listNode->val == treeNode->val) {
            return dfs(treeNode->right, listNode->next) || dfs(treeNode->left, listNode->next);
        }

        return false;
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) {
            return false;
        }
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};