// Recursion/ Union, Time Complexity: O(), Space Complexity: O(n+m). (n:root1 노드 갯수, m:root2 노드 갯수)
// idea: Union(합집합) 개념 : merge(root1, root2) = root1 | root2.

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr)    return root2;
        if(root2 == nullptr)    return root1;
        
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
    }
};
