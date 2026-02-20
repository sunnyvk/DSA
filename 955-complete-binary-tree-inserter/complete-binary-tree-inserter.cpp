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
class CBTInserter {
public:
TreeNode* root_ = nullptr;
    CBTInserter(TreeNode* root) {
       root_ = root;
    }
    
    int insert(int val) {
         queue<TreeNode*> q;
        q.emplace(root_);
        TreeNode* curr = nullptr;
         while(!q.empty()) {
             curr = q.front();
            q.pop();
             if(!curr->left) {
                curr->left = new TreeNode(val);
                break;
            }
             if(!curr->right) {
                curr->right = new TreeNode(val);
                break;
            }
             if(curr->left)
                q.emplace(curr->left);
            if(curr->right)
                q.emplace(curr->right);
         }
         return curr->val;
    }
    
    TreeNode* get_root() {
        return root_;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */