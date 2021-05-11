// 출제의도: "Symmetric 개념 이해/구현 능력(재귀)", Time Complexity: O(n).

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)   return true;
        return isMirror(root->left,root->right);
    }
    
    bool isMirror(TreeNode *root1, TreeNode *root2) {
        if(root1==nullptr && root2==nullptr)    return true;
        if(root1==nullptr || root2==nullptr)    return false;
        return (root1->val==root2->val) && isMirror(root1->right,root2->left) && isMirror(root1->left,root2->right);
    }
};
