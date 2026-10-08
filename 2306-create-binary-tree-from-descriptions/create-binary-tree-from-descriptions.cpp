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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        // Map value -> TreeNode*
        unordered_map<int, TreeNode*> nodes;
        
        // Stores all nodes that have a parent
        unordered_set<int> hasParent;

        for (auto& d : descriptions) {
            
            int parent = d[0];
            int child = d[1];
            int isLeft = d[2];

            // Create parent node if it doesn't exist
            if (!nodes.count(parent)) {
                nodes[parent] = new TreeNode(parent);
            }

            // Create child node if it doesn't exist
            if (!nodes.count(child)) {
                nodes[child] = new TreeNode(child);
            }

            // Connect child to parent
            if (isLeft == 1) {
                nodes[parent]->left = nodes[child];
            } 
            else {
                nodes[parent]->right = nodes[child];
            }

            // Child has a parent, so it cannot be the root
            hasParent.insert(child);
        }

        // The root is the node that never appeared as a child
        for (auto& [value, node] : nodes) {
            if (!hasParent.count(value)) {
                return node;
            }
        }

        return nullptr;
    }
};
