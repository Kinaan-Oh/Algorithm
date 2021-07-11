// "Recursion", Time Complexity: O(n), Space Complexity: O(h) (n: 트리의 노드 갯수, h: 트리의 높이)
// invert는 각 트리 노드의 left subtree와 right subtree의 위치를 바꿈을 의미한다.

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)   return nullptr;
        
        TreeNode* leftInverted = invertTree(root->left);
        TreeNode* rightInverted = invertTree(root->right);   
        root->left = rightInverted;
        root->right = leftInverted;
        return root;
    }
};
