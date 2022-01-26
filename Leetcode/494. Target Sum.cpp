// Recursion with Memoization, Time Complexity: O(mn), Space Complexity: O(mn) (m: sum의 범위(-1000~1000), n: nums.size)
// Memoization으로 dfs의 중복연산을 제거하여 Brute-Force의 time complexity O(2^n)을 O(mn)으로 개선.

class Solution {
private:
    int dp[2001][20];
    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        fill(&dp[0][0], &dp[2000][19]+1, 0);
        return dfs(nums, target, 0, nums.size()-1);
    }
    
    int dfs(vector<int>& nums, int target, int sum, int cur) {
        if(cur==-1 && sum == target)  return 1;
        else if(cur==-1 && sum != target)    return 0;
        else if(dp[sum+1000][cur])    return dp[sum+1000][cur];
        
        dp[sum+1000][cur] = dfs(nums, target, sum-nums[cur], cur-1) + dfs(nums, target, sum+nums[cur], cur-1);
        return dp[sum+1000][cur]; 
    }
};
