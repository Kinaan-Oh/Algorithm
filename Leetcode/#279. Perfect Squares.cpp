// 출제의도: DP, Time Complexity: O(n*sqrt(n)), Space Complexity: O(n)
// dp[i]: i를 만들 수 있는 최소 perfect square number 갯수. 점화식: dp[i] = min(dp[i], dp[k]+1) (k: <=i 이고 perfect square number 인 모든 수)

class Solution {
public:
    int numSquares(int n) {
        int dp[n+1];
        int m = (int)sqrt(n);
        int perfect_squares[m];
        
        fill(&dp[0], &dp[n+1], INT_MAX);
        for(int i=0;i<m;i++) {
            perfect_squares[i] = pow(i+1,2);
            dp[(int)pow(i+1,2)] = 1;
        }
        
        for(int i=1;i<=n;i++) {
            for(int j=0;j<m;j++) {
                if(i<=perfect_squares[j])    break;
                dp[i] = min(dp[i], dp[i-perfect_squares[j]]+1);
            }
        }
        return dp[n];
    }
};
