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
int MOD=1e9 + 7;
long SUM=0;
long maxP=0;
int totalSum(TreeNode* root){
    if(root==NULL)
    return 0;
    int leftSubtreeSum=totalSum(root->left);
    int rightSubtreeSum=totalSum(root->right);
    long  subtreeSum=root->val+leftSubtreeSum+rightSubtreeSum;

    long remainingSubtreeSum=SUM-subtreeSum;
    maxP=max(maxP,subtreeSum*remainingSubtreeSum);
    return subtreeSum;
}
    int maxProduct(TreeNode* root) {
        if(root==NULL){
            return 0;
        } 
        maxP=0;
        SUM=totalSum(root);
        totalSum(root);
        return maxP%MOD;

    }
};