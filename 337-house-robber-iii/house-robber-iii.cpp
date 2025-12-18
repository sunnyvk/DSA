/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * }
 */
class Solution {
public:
    struct State {
        int notRob; // max money if this node is NOT robbed
        int rob;    // max money if this node IS robbed
    };

    State dfs(TreeNode* root) {
        if (root == NULL) return {0, 0};

        State left = dfs(root->left);
        State right = dfs(root->right);

        State cur;

        // If we rob current node, we cannot rob children
        cur.rob = root->val + left.notRob + right.notRob;

        // If we do NOT rob current node, we choose best of children
        cur.notRob = max(left.notRob, left.rob)
                   + max(right.notRob, right.rob);

        return cur;
    }

    int rob(TreeNode* root) {
        State res = dfs(root);
        return max(res.notRob, res.rob);
    }
};
