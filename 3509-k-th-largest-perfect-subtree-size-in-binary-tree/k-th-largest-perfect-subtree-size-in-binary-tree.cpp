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
  vector<int>ans;
pair<bool,int> make_tree(TreeNode* root){
    if(root==NULL){
        return {true,0};
    }
    pair<bool,int> lefttr=make_tree(root->left);
    pair<bool,int> righttr=make_tree(root->right);
    if(lefttr.first &&  righttr.first && lefttr.second==righttr.second){
        int sum=lefttr.second+righttr.second+1;
        ans.push_back(sum);
        return {true,sum};
    }
    return {false,0};
}
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        if(root==NULL) return -1;

        make_tree(root);
        sort(ans.begin(),ans.end(),greater<int> ());
        if(ans.size()>=k){
            return ans[k-1];
        }
        return -1;
    }
};