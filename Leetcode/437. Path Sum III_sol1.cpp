// Brute-Force, Time Complexity: O(n^2), Space Complexity: O(n). (n: num of nodes) 
// 각 노드를 시작점으로하는 path 탐색. 
// call stack은 maximum n회 쌓이므로 space complexity O(n). 

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)    return 0;
            
        int num_of_path = dfs(root, 0, targetSum);
        
        num_of_path += pathSum(root->left, targetSum);
        num_of_path += pathSum(root->right, targetSum);
        return num_of_path;
    }
    
    int dfs(TreeNode* root, int prevSum, int targetSum) {
        if(root == nullptr)    return 0;
        
        int curSum = prevSum + root->val;
        int num_of_path = (curSum == targetSum) ? 1: 0;
        
        num_of_path += dfs(root->left, curSum, targetSum);
        num_of_path += dfs(root->right, curSum, targetSum);
        return num_of_path;
    }
};
