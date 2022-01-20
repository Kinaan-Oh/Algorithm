// 단순한 dfs 방식을 시도했으나 fail. 좀 더 고민 필요.

class Solution {  
public:
    int rob(TreeNode* root) {
        return max(max_amount(root, true), max_amount(root, false));
    }
    
    int max_amount(TreeNode* root, bool include) {
        if(root == nullptr)    return 0;
            
        if(include) return root->val + max_amount(root->left, false) + max_amount(root->right, false);
        return max_amount(root->left, true) + max_amount(root->right, true);
    }
};
