// DP(Top-Down), Time Complexity: O(mn), Space Complexity: O(mn). (m: target, n: nums.size)
// 각 dfs결과를 Memoize하여 중복계산 방지. int 대신 optional<bool>를 이용하여 메모리사용 최소화.

// refactor: dfs 매개변수로 leftover를 사용함으로서 매개변수 갯수를 2개에서 1개로 줄임.

class Solution {
private:
    optional<bool>  dp[10001][200];
    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        
        fill(&dp[0][0], &dp[10000][199]+1, nullopt);
        for(auto num: nums)    sum += num;
        if(sum%2)   return false;
        sum /= 2;
        return dfs(nums, sum, 0);
    }
    
    bool dfs(vector<int>& nums, int leftover, int cur) {
        if(leftover == 0)   return true;
        else if(leftover<0 || cur == nums.size())    return false;
        else if(dp[leftover][cur] != nullopt)  return dp[leftover][cur] == true;   
            
        dp[leftover][cur] = dfs(nums, leftover, cur+1) || dfs(nums, leftover-nums[cur], cur+1);
        return dp[leftover][cur] == true;
    }
};
