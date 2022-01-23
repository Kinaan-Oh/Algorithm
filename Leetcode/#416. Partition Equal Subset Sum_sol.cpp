// DP(Top-Down), Time Complexity: O(mn), Space Complexity: O(mn). (m: target, n: nums.size)
// 각 dfs결과를 Memoize하여 중복계산 방지. int 대신 optional<bool>를 이용하여 메모리사용 최소화.

class Solution {
private:
    optional<bool> dp[10001][200];  // [sum to make][start index]
    
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        
        fill(&dp[0][0], &dp[10000][199]+1, nullopt);
        for(auto num: nums)  target += num;
        if(target%2)  return false;
        target /= 2;
        return dfs(nums, target, 0, 0);
    }
    
    bool dfs(vector<int>& nums, int target, int sum, int end) {
        if(sum == target)   return true;
        else if(sum > target || end == nums.size())    return false;
        else if(dp[target-sum][end] != nullopt)    return dp[target-sum][end] == true;
        
        dp[target-sum][end] = dfs(nums, target, sum, end+1) || dfs(nums, target, sum+nums[end], end+1);
        return dp[target-sum][end] == true;
    }
};
