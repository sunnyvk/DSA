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
int MOD=1e9+7;
int SUM=0;
long long maxP=0;
long long totalSum(TreeNode* root){
    if(root==NULL) return 0;
    int leftsum=totalSum(root->left);
     long long rightsum=totalSum(root->right);
     long long subtreeSum=root->val+leftsum+rightsum;
     long long  remainingSum=SUM-subtreeSum;
     maxP=max(maxP,subtreeSum*remainingSum);
     return subtreeSum;
}
    int maxProduct(TreeNode* root) {
       SUM=totalSum(root);
       totalSum(root);
       return maxP%MOD;
    }
};