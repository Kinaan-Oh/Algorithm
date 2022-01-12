// 출제의도: DP, Time Complexity: O(mn), Space Complexity: O(mn) (m: grid.size, n:grid[0].size)
// dp[i][j] : 목적지 (row:i, col:j)까지의 최소 경로 비용. dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]. (grid 값은 0이상이라는 조건때문에, 오른쪽 혹은 아래쪽으로만 이동해야만 한다.)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        
        fill(&dp[0][0], &dp[m-1][n-1], 0);
        dp[0][0] = grid[0][0];
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i==0 && j==0)    continue;
                
                int from_top = i-1>=0 ? dp[i-1][j] : INT_MAX;
                int from_left = j-1>=0 ? dp[i][j-1] : INT_MAX;
                dp[i][j] = min(from_top, from_left) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
