// "Bottom-up DP", Time Complexity: O(n), Space Complexity: O(n).

class Solution {
private:
    int dp[46];
    
public:
    int climbStairs(int n) {
        dp[1] = 1, dp[2] = 2;
        
        for(int i=3;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
