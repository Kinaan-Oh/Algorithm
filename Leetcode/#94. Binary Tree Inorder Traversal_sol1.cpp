// Inorder Traverse Resulsively. Time Complexity: O(N), Space Complexity: O(N)(System Stack)

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
    vector<int> nodeInorderTraversed;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        LVR(root);
        return nodeInorderTraversed;
    }
    
    void LVR(TreeNode *node) {
        if(node==nullptr)   return;
        
        if(node->left)  LVR(node->left);
        nodeInorderTraversed.push_back(node->val);
        if(node->right)   LVR(node->right);
    }
};
