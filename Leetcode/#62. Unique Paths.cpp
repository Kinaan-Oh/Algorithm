// 출제의도: DP, Time Complexity: O(mn), Space Complexity: O(mn).
// dp[i][j] : 목적지 (row:i, col:j)에 대한 Unique Paths 갯수. dp[i][j] = dp[i-1][j] + dp[i][j-1]. (이동방향은 오른쪽, 아래쪽 이라는 제약조건으로 인해 성립가능)
// 한국에서 고등학교를 나온 평범한 학생이라면 매우 쉽게 풀수 있는 유형.

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        
        fill(&dp[0][0], &dp[m-1][n-1], 0);
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 || j==0)    {
                    dp[i][j] = 1;
                    continue;
                }
                
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
