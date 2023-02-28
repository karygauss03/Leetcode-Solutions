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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> frequency;
        vector<TreeNode*> result;
        findDuplicates(root, frequency, result);
        return result;
    }
    
private:
    string findDuplicates(TreeNode* node, unordered_map<string, int>& frequency, vector<TreeNode*>& result) {
        if (!node) {
            return "#";
        }
        
        string leftIdentifier = findDuplicates(node->left, frequency, result);
        string rightIdentifier = findDuplicates(node->right, frequency, result);
        // this thing simply means if two string having same identifier i.e. 4,#,# and 4,#,# it means we found two same subtree 
        string identifier = to_string(node->val) + "," + leftIdentifier + "," + rightIdentifier;
        frequency[identifier]++;
        
        if (frequency[identifier] == 2) {
            result.push_back(node);
        }
        
        return identifier;
    }
};
