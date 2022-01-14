// 출제의도: DP, Time Complexituy: O(mn), Space Complexity: O(mn) (m: matrix.size, n:matrix[0].size)
// dp[i][j]: i,j를 우측하단으로 포함하는 1로 구성된 최대 정사각형 변의 길이. 점화식: dp[i][j] = min{dp[i-1][j], dp[i][j-1], d[i-1][j-1]} + 1.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m+1][n+1];
        int max_length = 0;
        
        fill(&dp[0][0], &dp[m][n], 0);
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]=='0')   continue;
                
                dp[i+1][j+1] = min(min(dp[i][j+1], dp[i+1][j]), dp[i][j]) + 1;
                max_length = max(max_length, dp[i+1][j+1]);
            }
        }
        return max_length * max_length;
    }
};
