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
    int val=0;
    vector< vector<int> > dp;
    int minCameraCover(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)return 1;
        number(root);
        dp.resize(val,vector<int>(4,-1));
		// root node doesnt has parent , so only case 1 and 2 can be valid for it 
		// and our answer will be minimum of both cases 
        return min( camera(root,0) , camera(root,1) ) ;
    }
    //number all nodes starting from 0
    void number(TreeNode *root){
        if(root == NULL)return ;
        root->val = val++;
        number(root->left);
        number(root->right);
    }
    
    int camera(TreeNode *root,int j){
        if(root == NULL)return 0;
        int i=root->val;
        if(dp[i][j] != -1)return dp[i][j];
        if(j == 0){
		  // this is very special condition , here at least one of the children must have camera
		  //if there is no children then node itself will have the camera to monitor itself 
           if(root->left && root->right){
               dp[i][j] = camera(root->left,1) + camera(root->right,1);
               dp[i][j] = min(dp[i][j],camera(root->left,1) + camera(root->right,0));
               dp[i][j] = min(dp[i][j],camera(root->left,0) + camera(root->right,1));
           }
           else if(root->left){
               dp[i][j] = camera(root->left,1);
           }
            else if(root->right){
              dp[i][j] = camera(root->right,1);  
            }
            else dp[i][j]=1;
        }
        else if(j == 1 || j==3){
            dp[i][j] = 1;
            dp[i][j] += min(camera(root->left,2) , camera(root->left,3));
            dp[i][j] += min(camera(root->right,2) , camera(root->right,3));
        }
        else if(j == 2){
            dp[i][j] = 0;
            dp[i][j] += min(camera(root->left,0) , camera(root->left,1));
            dp[i][j] += min(camera(root->right,0) , camera(root->right,1));
        }
        return dp[i][j];
    }
};