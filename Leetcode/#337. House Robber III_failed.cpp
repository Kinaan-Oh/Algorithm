// dfs.
// Time Limit Exceeded. 122 / 124 test cases passed.
// 주의: root를 방문하지 않은 경우, child를 1) 방문하는 경우 2) 방문하지 않는 경우 모두 고려해주어야 함. 

class Solution {  
public:
    int rob(TreeNode* root) {
        return max(max_amount(root, true), max_amount(root, false));
    }
    
    int max_amount(TreeNode* root, bool include) {
        if(root == nullptr)    return 0;
            
        if(include) return root->val + max_amount(root->left, false) + max_amount(root->right, false);
        return max(max_amount(root->left, true), max_amount(root->left, false)) +
            max(max_amount(root->right, true), max_amount(root->right, false));
    }
};
