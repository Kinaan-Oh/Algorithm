// DP, Time Complexity: O(n), Space Complexity: O(n) (n: cost.size)
// 논리: n번째 계단에 도달하는 최소 비용 = min(n-1번째 계단에 도달하는 최소비용, n-2번째 계단에 도달하는 최소비용)

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        
        for(int i=2;i<n;i++) {
            dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2]);
        }
        return min(dp[n-1]+cost[n-1], dp[n-2]+cost[n-2]);
    }
};
