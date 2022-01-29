// Prefix Sum, Time Complexity: O(n), Space Complexity: O(n) (n: num of nodes)
// dp: [prefix sum : num of prefix sum]
// root node에서 cur node 까지의 val의 sum을 curSum이라 할 때,
// cur node를 leaf node로 포함하는 path 중 sum이 targetSum과 같은 것을 찾는 것은
// dp[curSum] - dp[prevSum] = targetSum <-> dp[prevSum] = dp[curSum] - targetSum 을 만족하는 prevSum의 갯수를 구하는 것과 같다.
// dp[prevSum]은 이미 거쳐온 path와 관련되어 이미 dp에 그 갯수 memoize되어 있다.
// 따라서, 각 노드를 leaf node로 하는 path 중 sum이 targetSum이 되는 path의 갯수를 구할 수 있다.
// 주의할 것은 탐색한 노드에서 return 될 때, dp를 원래 상태로 갱신해주어야 한다. 

class Solution {
private:
    unordered_map<int, int> dp;
    int answer = 0;
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        dp[0] = 1;
        dfs(root, 0, targetSum);
        return answer;
    }
    
    void dfs(TreeNode* root, int prevSum, int targetSum) {
        if(root == nullptr)    return;
        
        int curSum = prevSum + root->val;
        
        answer += dp[curSum-targetSum];
        dp[curSum] += 1;
        dfs(root->left, curSum, targetSum);
        dfs(root->right, curSum, targetSum);
        dp[curSum] -= 1;
    }
};
