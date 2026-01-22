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
vector<int> ans;
    pair<bool,int> make_tree(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }
        pair<bool,int> left=make_tree(root->left);
        pair<bool,int> right=make_tree(root->right);
        if(left.first && right.first && left.second==right.second){
            int sum=left.second+right.second+1;
            ans.push_back(sum);
            return {true,sum};
        }
        return {false,0};
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
       if(root==NULL){
        return -1;
       }
       make_tree(root);
    sort(ans.rbegin(),ans.rend());
    if(ans.size()>=k){
        return ans[k-1];
    }
    return -1;
    }
};