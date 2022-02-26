// Recursion/Binary Tree, Time Complexity: O(mn), Space Complexity: O(h) (m: nodes of tree1, n: nodes of tree2, h: height of tree1)

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)   return false;
        if(isIdentical(root, subRoot))  return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr)    return true;
        else if(root1==nullptr || root2==nullptr)   return false;
        
        return root1->val==root2->val && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    }
};
