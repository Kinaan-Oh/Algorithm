// DP, Time Complexity: O(numRows^2), Space Complexity: O(numRows^2)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int dp[31][31];
        vector<vector<int>>    answer;
        
        fill(&dp[0][0], &dp[30][30]+1, 0);
        dp[1][1] = 1;
        answer.push_back({1});
        
        for(int i=2;i<=numRows;i++) {
            vector<int> row;
            
            for(int j=1;j<=i;j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                row.push_back(dp[i][j]);
            }
            answer.push_back(row);
        }
        return answer;
    }
};
