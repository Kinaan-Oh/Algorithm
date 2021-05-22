// 출제의도: "dp", Time Complexity: O(n^2), Space Complexity: O(1). (n: triangle.size)
// 점화식: dp[i][j]를 (i,j)까지의 최대값이라고 할 때, dp[r+1][c] = max(dp[r][c-1],dp[r][c]) + triangle[r+1][c] (단, c-1>=0,c<=r)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int sz = triangle.size();
    dp[0][0] = triangle[0][0];
    for(int r=0;r<sz-1;r++) {
        for(int c=0;c<=r+1;c++) {
            int left = c-1<0 ? 0 : dp[r][c-1];
            int up = c>r ? 0 : dp[r][c];
            dp[r+1][c] = max(left,up) + triangle[r+1][c]; 
            
            if(r+1==sz-1)   answer = max(answer, dp[r+1][c]);
        }
    }
    return answer;
}
