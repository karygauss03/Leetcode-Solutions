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

	int depth(TreeNode* root){
		if(root==NULL) return 0;
		
		int left = 1 + depth(root->left);
		int right = 1 + depth(root->right);
		
		return max(left,right);
	}
	
	void RSV(TreeNode* root,int k,vector<bool>& depth,vector<int>& res){
		if(root==NULL) return;
		
		if(root){
			if(depth[k]==false){
				depth[k]=true;
				res.push_back(root->val);
			}
			RSV(root->right,k+1,depth,res);
		}
		
		if(root){
			if(depth[k]==false){
				depth[k]=true;
				res.push_back(root->val);
			}
			RSV(root->left,k+1,depth,res);
		}
		
	}
	vector<int> rightSideView(TreeNode* root) {
		vector<int> res;
		int k = 0;
		int d = depth(root);
		vector<bool> deep(d+1,false);
		RSV(root,k,deep,res);
		return res;
	}
};