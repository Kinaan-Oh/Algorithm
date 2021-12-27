// 8ms으로 sol1과 동등한 성능. 
// 점화식 : diameter = Max of 1) diameter of left subtree
//                          2) diameter of right subtree
//                          3) depth of left subtree + depth of right subtree

class Solution {
private:
    unordered_map<TreeNode*,int>    depth;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return diameter(root);
    }
    
    int diameter(TreeNode* root) {
        if(root == nullptr) return 0;
        
        return max(max(diameter(root->left), diameter(root->right)), depth[root->left]+depth[root->right]);
    }
    
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        depth[root] = max(maxDepth(root->left), maxDepth(root->right)) + 1;
        return depth[root];
    }
};
