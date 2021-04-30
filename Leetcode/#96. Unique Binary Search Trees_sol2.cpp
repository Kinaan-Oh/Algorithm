// N사 1차 면접에서 출제된 문제. Iterative DP. Time Complexity: O(n^2), Space Complexity: O(n).

class Solution {
private:
    int dp[20];  // idx: 0~19
public:
    int numTrees(int n) {
        dp[0]=1;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<i;j++) {
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        return dp[n];
    }
};
