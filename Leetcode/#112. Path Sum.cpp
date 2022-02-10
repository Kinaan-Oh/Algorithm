// 출제의도: DFS/ LeafNode, Time Complexity: O(n), Space Complexity: O(n) (n: num of nodes)
// BestCase: Balanced Binary Tree인 경우 Space Complexity는 O(lgn), Worse Case: Skewed Binary Tree인 경우 Time Complexity는 O(n).

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)    return false;
        
        targetSum -= root->val;
        if(root->left == nullptr && root->right == nullptr)    return targetSum == 0;
        
        bool ret = false;
        
        ret = hasPathSum(root->left, targetSum);
        if(ret)    return ret;
        
        return hasPathSum(root->right, targetSum);
    }
};
