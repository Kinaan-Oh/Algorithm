// 출제의도: BST Traverse, Time Complexty: O(V), Space Complexity: O(V) (V: num of vertices)
// reverse inorder traverse(RVL)로 간단하게 해결 가능.

class Solution {
private:
    int sum = 0;
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        RVL(root);
        return root;
    }
    
    void RVL(TreeNode* root) {
        if(root == nullptr)    return;
        
        RVL(root->right);
        sum += root->val;
        root->val = sum;
        RVL(root->left);
    }
};
