// "Recursion", Time Complexity: O(n), Space Complexity: O(n) (n: root1과 root2의 전체 트리노드 갯수)

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr && root2==nullptr)    return nullptr;
        
        TreeNode* root = new TreeNode((root1==nullptr?0:root1->val)+(root2==nullptr?0:root2->val));
        root->left = mergeTrees((root1==nullptr?nullptr:root1->left), (root2==nullptr?nullptr:root2->left));
        root->right = mergeTrees((root1==nullptr?nullptr:root1->right), (root2==nullptr?nullptr:root2->right));
        return root;
    }
};
